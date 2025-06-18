class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> after(2, vector<int> (k+1,0)); 
        vector<vector<int>> curr(2, vector<int> (k+1,0)); 

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int t = 1; t<=k; t++){
                    if(buy == 1){ // can buy 
                        curr[1][t] = max(-prices[i] + after[0][t], after[1][t]); // not buy and buy 
                    }else{ // can not buy
                        curr[0][t] = max(prices[i] + after[1][t-1], after[0][t]); // not sell and sell 
                    }
                    
                }
            }
            after = curr;
        }

        return after[1][k];
        
    }
};