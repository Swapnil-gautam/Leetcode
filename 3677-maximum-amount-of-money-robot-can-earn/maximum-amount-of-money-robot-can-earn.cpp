class Solution {
public:
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int lifeline){
        if(i >= coins.size() || j >= coins[0].size()) return -1e9;

        if(i == coins.size()-1 && j == coins[0].size()-1){
            if(coins[i][j]>= 0){
                return coins[i][j];
            }else{
                if(lifeline>0){
                    return 0;
                }else{
                    return coins[i][j];
                }
            }
            
        }

        if(t[i][j][lifeline] != INT_MIN) {
            return t[i][j][lifeline];
        }

        int right = -1e9;
        int down = -1e9; 
        
        if(i < coins.size() && j < coins[0].size()){
            if(coins[i][j] > 0){
                right = coins[i][j] + solve(coins, i, j+1, lifeline);
                down = coins[i][j] + solve(coins, i+1, j, lifeline);
            }else{
                // right = max(coins[i][j] + solve(coins, i, j+1, lifeline), solve(coins, i, j+1, lifeline-1));
                // down = max(coins[i][j] + solve(coins, i+1, j, lifeline), solve(coins, i+1, j, lifeline-1));

                // take loss
                right = coins[i][j] + solve(coins, i, j+1, lifeline);
                down  = coins[i][j] + solve(coins, i+1, j, lifeline);

                // use lifeline (only if available)
                if(lifeline > 0){
                    right = max(right, solve(coins, i, j+1, lifeline-1));
                    down  = max(down, solve(coins, i+1, j, lifeline-1));
                }
            }
            
        }
        return t[i][j][lifeline] = max(right, down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int sum = 0;
        int lifeline = 2;
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, 0, 0, lifeline);
    }
};