class Solution {
public:
    // int rec(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    //     if(i < 0 || j < 0 || obstacleGrid[i][j] == 1){
    //         return 0;
    //     }
    //     if( i == 0 && j == 0){
    //         return 1;
    //     }
    //     // cout << " i: " << i << " j: " << j << endl;
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int up = rec(i-1,j,obstacleGrid, dp);
    //     int left = rec(i,j-1,obstacleGrid, dp);

    //     return dp[i][j] = (up + left);
    // }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prev(m, 0);

        for(int i = 0; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++){
                
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                }
                else if( i == 0 && j == 0){
                    curr[j] = 1;
                }
                else{
                    int up = 0; int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[m-1];
        // return rec(m-1,n-1,obstacleGrid, dp);
    }
};