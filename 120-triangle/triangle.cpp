class Solution {
public:

    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& grid){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(grid[i][j] != INT_MIN){
            // cout << "grid[i][j]: " << i << " : " << j << " : " << grid[i][j] <<  endl;
            return grid[i][j];
        }
        
        int down = solve(triangle, i+1, j, grid);
        int diag = solve(triangle, i+1, j+1, grid);

        grid[i][j] = triangle[i][j] + min(down, diag);
        // cout << "i: " << i << " j: " << j << " " << grid[i][j] << endl;
        return grid[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> grid(n, vector<int>(m, INT_MIN));
        // int sum = 0;
        // for(int i = 0; i < triangle.size(); i++){
        //     int min = INT_MAX;
        //     for(int j = 0; j < triangle[i].size(); j++){
        //         if(triangle[i][j] < min){
        //             min = triangle[i][j];
        //         }
        //     }
        //     sum = sum + min;
        // }
        // return sum;
        int sum = 0;
        return solve(triangle, 0, 0, grid);
    }
};