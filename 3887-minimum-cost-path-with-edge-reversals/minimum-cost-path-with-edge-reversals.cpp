class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int, vector<pair<int, int>>>adj;
        vector<int> min_dist(n, INT_MAX);
        min_dist[0] = 0;
    
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]*2});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            int curr_dist = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if(curr_node == n-1){
                return min_dist[curr_node];
            }
            for(auto &nbr : adj[curr_node]){
                int node = nbr.first;
                int dist = nbr.second;
                // cout <<"node: " << nbr.first << " dist: " << nbr.second << endl;
                if((curr_dist+dist) < min_dist[node]){
                    min_dist[node] = curr_dist+dist;
                    pq.push({curr_dist+dist, node});
                }
            }
        }
        return -1;

    }
};

