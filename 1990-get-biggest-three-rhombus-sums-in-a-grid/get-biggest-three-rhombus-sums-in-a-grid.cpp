class Solution {
public:
    int checkmaxRhom(vector<vector<int>>& grid, int i, int j, priority_queue<int>& max_pq ){
        int maxRhom = grid[i][j];
        max_pq.push(maxRhom);
        int n = grid.size();
        int m = grid[0].size(); 
        int k = 1;
        while(i+k < n && i-k >=0 && j+k < m && j-k >=0){
            // cout << "k: " << k << " ";
            int Sum = grid[i+k][j]+grid[i-k][j]+grid[i][j+k]+grid[i][j-k];
            int t = 1;
            while(t<k){
                Sum = Sum + grid[i+k-t][j-t]+grid[i-k+t][j+t]+grid[i+t][j+k-t]+grid[i-t][j-k+t];
                t++;
            }
            // maxRhom = max(maxRhom, Sum);
            max_pq.push(Sum);
            k++;
        }
        // cout << endl;
        return maxRhom;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> romgrid(n, vector<int>(m,0));
        vector<int> resvec;
        priority_queue<int> max_pq;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // cout << grid[i][j] << " ";
                // romgrid[i][j] = checkmaxRhom(grid, i, j);
                checkmaxRhom(grid, i, j, max_pq);
            }
            // cout << endl;
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << romgrid[i][j] << " ";
        //         // romgrid = checkmaxRhom(grid, i, j);
        //     }
        //     cout << endl;
        // }

        int t = 0;
        resvec.push_back(max_pq.top());
        max_pq.pop();
        while(!max_pq.empty() && t < 2){
            // cout <<"max_pq.top(): " << max_pq.top() << endl;
            // cout <<"resvec.back(): " << resvec.back() << endl;
            if(max_pq.top() != resvec.back()){
                resvec.push_back(max_pq.top());
                t++;
            }
            max_pq.pop();
        }

        return resvec;
    }
};