class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited, string s, string e, double& prd, double& res){
        if(visited.find(s)!=visited.end()){
            return;
        }
        visited.insert(s);
        if(s==e){
            res = prd;
            return;
        }
        for (auto it : adj[s]) {
            double val = it.second;
            string v = it.first;
            prd *= val;
            dfs(adj, visited, v, e, prd, res);
            prd /= val; 
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i < equations.size(); i++){
            adj[equations[i][0]].push_back(pair(equations[i][1], values[i]));
            adj[equations[i][1]].push_back(pair(equations[i][0], (1/values[i])));
        }
        vector<double> resvec;
        for(int i = 0; i < queries.size(); i++){
            double prd = 1;
            double res = -1;
            string s = queries[i][0];
            string e = queries[i][1];
            unordered_set<string> visited;
            if (adj.find(s) != adj.end()) {
                // cout << "check " << endl;
                dfs(adj, visited, s, e, prd, res);
            }            
            resvec.push_back(res);
        }

        return resvec;
    }
};