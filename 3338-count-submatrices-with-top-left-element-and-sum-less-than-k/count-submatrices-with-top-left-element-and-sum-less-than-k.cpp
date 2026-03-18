class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0; 
        int m = grid.size();
        int n = grid[0].size();

        // int sum = 0;
        for(int i = 1; i < m; i++){
            // sum = sum + grid[i][0];
            // if(sum < k){
            //     count++;
            // }
            grid[i][0] = grid[i][0] + grid[i-1][0];
            if(grid[i][0] <= k){
                count++;
            }
        }
        // // cout << "count: " << count << endl;

        // sum = 0;
        for(int i = 1; i < n; i++){
            // sum = sum + grid[0][i];
            // if(sum < k){
            //     count++;
            // }
            grid[0][i] = grid[0][i] + grid[0][i-1];
            if(grid[0][i] <= k){
                count++;
            }
        }
        // // cout << "count: " << count << endl;

        // sum = 0;
        // int t = min(m, n);
        // int p = 1;
        // while(p <= t){
        //     sum = 0;
        //     for(int i = 0; i < p; i++){
        //         for(int j = 0; j < p; j++){
        //             sum = sum + grid[i][j];
        //         }
        //     }
        //     if(sum <= k){
        //         count++;
        //     }else{
        //         break;
        //     }
        //     p++;
        // }

        // cout << "count: " << count << endl;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] = grid[i][j] + grid[i-1][j] + (grid[i][j-1] - grid[i-1][j-1]);
                if(grid[i][j] <= k){
                    count++;
                }
            }
        }

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){ 
        //         cout << grid[i][j] << " ";
        //         // if(grid[i][j] <= k){
        //         //     count++;
        //         // }
        //     }
        //     cout << endl;
        // }

        if(grid[0][0] <= k){
            count = count + 1;
        }

        return count;
    }
};