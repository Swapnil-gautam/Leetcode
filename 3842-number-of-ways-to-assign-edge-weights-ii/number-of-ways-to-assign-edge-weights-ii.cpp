// class Solution {
// public:
//     static constexpr long long MOD = 1e9 + 7;

//     long long power(long long base, long long exponent) {
//         if (exponent == 0)
//             return 1;

//         long long half = power(base, exponent / 2);

//         long long result = (half * half) % MOD;

//         if (exponent % 2 == 1) {
//             result = (result * base) % MOD;
//         }

//         return result;
//     }

//     int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {

//         int depth = 0;

//         for (int neighbor : adj[node]) {
//             if (neighbor == parent)
//                 continue;

//             depth = max(depth, getMaxDepth(adj, neighbor, node) + 1);
//         }

//         return depth;
//     }

//     int getedgesbtwn(unordered_map<int, vector<int>>& adj, grid, int curr, int tar){
//         vector<vector<int>>
//     };

//     vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {

//         unordered_map<int, vector<int>> adj;
//         vector<int> res;
//         int n = 1;

//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];

//             if(n < v){
//                 n = v;
//             }

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         // cout << max_node << endl;
//         vector<vector<int>> grid(vector<int>(n,0),0);

//         // int maxDepth = getMaxDepth(adj, 1, 0);
//         for(auto& q: queries){
//             edgesbtwn = getedgesbtwn(adj, grid, q[0], q[1]);
//         }

//         // return power(2, maxDepth - 1);
//         return res;
//     }
// };




class Solution {
public:
    int M = 1e9+7;
    int n;
    int cols;

    unordered_map<int, vector<int>> adj;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int root, int parent) {
        ancestorTable[root][0] = parent;

        for(int &ngbr : adj[root]) {
            if(ngbr == parent) continue;

            depth[ngbr] = depth[root] + 1;

            dfs(ngbr, root);
        }
    }

    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1)
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
            }
        }
    }

    int findLCA(int u, int v) {
        if(depth[u] < depth[v])
            swap(u, v);
        
        int k = depth[u] - depth[v];

        for(int j = 0; j < cols; j++) {
            if(k & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) { //both were on the same path
            return u; //LCA
        }

        for(int j = cols-1; j >= 0; j--) {
            if(ancestorTable[u][j] == -1) {
                continue;
            }

            if(ancestorTable[u][j] != ancestorTable[v][j]) { //still different, then keep jumping
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0]; //LCA
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n    = edges.size()+1;
        cols = log2(n)+1;

        for(auto &edge : edges) {
            int u = edge[0]-1;
            int v = edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.resize(n, 0);
        ancestorTable.resize(n, vector<int>(cols, -1));

        dfs(0, -1);
        buildAncestorTable();

        //Precompute power of 2
        vector<int> pow2(n+1);
        pow2[0] = 1;
        for(int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i-1]) % M;
        }

        vector<int> result;
        for(auto &query : queries) {
            int u = query[0] - 1;
            int v = query[1] - 1;

            int lca = findLCA(u, v);
            int d = depth[u] + depth[v] - 2*depth[lca];

            if(d == 0) {
                result.push_back(0);
            } else {
                result.push_back(pow2[d-1]);
            }
        }

        return result;
    }
};
