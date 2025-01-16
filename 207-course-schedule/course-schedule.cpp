class Solution {
public:
    bool dfs( int node, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[node] == 1){
            return true;
        }
        if(visited[node] == 2){
            return false;
        }
        
        visited[node] = 1;

        for (int next : adj[node]) {
            if(dfs(next, adj, visited)){
                return true;;
            }   
        }

        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // unordered_map<int , int> mp;
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto i: prerequisites){
            // adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }

        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                if(dfs(i, adj, visited)){
                    return false;
                }   

            }
        }

        
        // for(auto i: adj){
        //     if(i[0] != NULL){
        //         cout << i[0] << endl;
        //     }
        // }


        return true;

    }
};