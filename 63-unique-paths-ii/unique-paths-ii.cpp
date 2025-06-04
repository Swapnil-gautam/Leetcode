class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1){
            return 0;
        }
        if( i == 0 && j == 0){
            return 1;
        }
        // cout << " i: " << i << " j: " << j << endl;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = rec(i-1,j,obstacleGrid, dp);
        int left = rec(i,j-1,obstacleGrid, dp);

        return dp[i][j] = (up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return rec(m,n,obstacleGrid, dp);
    }
};