class Solution {
public:
    int MaxSqr(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0' ){
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = 1 + min( MaxSqr(matrix, i+1, j, dp), min(MaxSqr(matrix, i, j+1, dp), MaxSqr(matrix, i+1, j+1, dp)));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1,-1));
        int MaxArea = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == '1'){
                    // cout << " i: " << i << " j: " << j << endl;
                    int MaxWidth = MaxSqr(matrix, i, j, dp);
                    // cout << " i: " << i << " j: " << j << " MaxWidth: " << MaxWidth << endl;
                    MaxArea = max(MaxArea, MaxWidth*MaxWidth);
                }
            }
        }

        return MaxArea;
    }
};