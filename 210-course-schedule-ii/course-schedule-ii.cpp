class Solution {
public:
    bool acyclic(int i, vector<vector<int>>& adj, vector<bool>& todo, vector<bool>& done, vector<int>& order){
        if(todo[i] == true){
            return false;
        }
        if(done[i] == true){
            return true;
        }
        todo[i] = true;
        done[i] = true;

        for(int j : adj[i]){
            //cout << i << " " << j << endl;
            if(!acyclic(j, adj, todo, done, order)){
                return false;
            }
        }

        //cout << " i push: " << i <<  endl;
        order.push_back(i);
        todo[i] = false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int> order;

        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> todo(n, false);
        vector<bool> done(n, false);
        for( int i = 0; i< n; i++){
            if(done[i] == false){
                if(!acyclic(i, adj, todo, done, order)){
                    return {};
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};