// class Solution {
// public:
    
//     int rec(vector<vector<int>>& grid, vector<vector<int>>& DPgrid, int i, int j, int sum ){
//         cout << "i: " << i << " j: " << j << endl;
//         if(i == 0 && j == 0){
//             cout << "end: "<< sum + grid[i][j] << endl;
//             return sum + grid[i][j];
//         }

//         if(DPgrid[i][j] != -1){
//             return DPgrid[i][j];
//         }
        
//         // sum = sum + grid[i][j];
//         cout << "sum: "<< sum << endl;
//         int r , d = INT_MAX;
//         if((j+1) < grid[0].size()){
//             r = rec(grid, DPgrid, i, j+1, sum + grid[i][j]);
//         }

//         if((i+1) < grid.size()){
//             d = rec(grid, DPgrid, i+1, j, sum + grid[i][j]);
//         }

//         sum = min(r, d);

//         cout << "i: "<< i << " j: " << j << " r: " << r << " d: " << d << " sum: " << sum << endl;
//         DPgrid[i][j] = sum;
//         return sum;

//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size()
//         int n = grid[0].size();
//         int sum = grid[m-1][n-1];
//         vector<vector<int>> DPgrid(m, vector<int>(n, -1));
//         return rec(grid, DPgrid, m-1, n-1, sum);
//     }
// };


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};

// Input:
// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]

// After processing:
// [1, 4, 5]
// [2, 7, 6]
// [6, 8, 7] 
