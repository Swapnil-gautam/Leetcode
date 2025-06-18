class Solution {
public:

    // int rec(vector<int>& prices, int i, bool buydone, int buyprice, int profit, int k, vector<vector<vector<int>>> dp){
    //     // cout << "i: " << i << " buydone: " << buydone << " k: " << k  << " buyprice: " << buyprice << endl; 

    //     // if(i == prices.size() || k == 0){
    //     //     return 0;
    //     // }

    //     if(i == prices.size()-1){
    //         if(buydone == true){
    //             profit = profit + (prices[i] - buyprice); 
    //         }
    //         // cout <<  " profit1: " << profit << endl;
    //         return  dp[i][buydone][k] = profit;
    //     }
    //     if(k == 0){
    //         // cout <<  " profit2: " << profit << endl;
    //         return dp[i][buydone][k] = profit;
    //     }

    //     if(dp[i][buydone][k] != -1){
    //         return dp[i][buydone][k];
    //     }

    //     if(buydone == true){
    //         // sell
    //         // profit = max(rec(prices, i-1, buydone, buyprice, profit,  k, dp) , rec(prices, i-1, false, buyprice, profit + (buyprice - prices[i]),  k-1, dp));
    //         profit = max(rec(prices, i+1, buydone, buyprice, profit,  k, dp) , rec(prices, i+1, false, buyprice, profit + (prices[i] - buyprice),  k-1, dp));

    //     }else{
    //         // buy
    //         // profit = max(rec(prices, i-1, buydone, buyprice, profit,  k, dp), rec(prices, i-1, true, prices[i], profit,  k, dp));
    //         profit = max(rec(prices, i+1, buydone, buyprice, profit,  k, dp), rec(prices, i+1, true, prices[i], profit,  k, dp));
    //     }

    //     // cout <<  " profit3: " << profit << endl;
    //     return dp[i][buydone][k] = profit;
    // }


    // int rec(vector<int>& prices, int i, bool buydone, int k, vector<vector<vector<int>>> dp){
    //     if(i == prices.size() || k == 0){
    //         return 0;
    //     }
    //     if(dp[i][buydone][k] != -1){
    //         return dp[i][buydone][k];
    //     }
    //     if(buydone == true){
    //         return  dp[i][buydone][k] = max(rec(prices, i+1, buydone, k, dp) , prices[i] + rec(prices, i+1, false,  k-1, dp)); // not sell and sell 
    //     }
    //     return dp[i][buydone][k] = max(rec(prices, i+1, buydone, k, dp), -prices[i] +rec(prices, i+1, true, k, dp)); // not buy and buy 
    // }

    // int maxProfit(vector<int>& prices) {
    //     bool buydone = false;
    //     int n = prices.size();
    //     // int i = n-1;
    //     int i = 0;
    //     int k = 2;
    //     int buyprice = INT_MIN;
    //     int profit = 0;
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1))); 
    //     // return rec(prices, i, buydone, buyprice, profit,  k, dp);
    //     return rec(prices, i, buydone, k, dp);
    // }

    // int maxProfit(vector<int>& prices) {

    //     int n = prices.size();
    //     int k = 2;

    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0))); 

    //     for(int i = n-1; i >= 0; i--){
    //         for(int buy = 0; buy <= 1; buy++){
    //             for(int k = 1; k<=2; k++){
    //                 if(buy == 1){ // can buy 
    //                     dp[i][buy][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]); // not buy and buy 
    //                 }else{ // can not buy
    //                     dp[i][buy][k] = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]); // not sell and sell 
    //                 }
                    
    //             }
    //         }
    //     }

    //     return dp[0][1][2];
    // }


    
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int k = 2;

        vector<vector<int>> after(2, vector<int> (3,0)); 
        vector<vector<int>> curr(2, vector<int> (3,0)); 

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int k = 1; k<=2; k++){
                    if(buy == 1){ // can buy 
                        curr[1][k] = max(-prices[i] + after[0][k], after[1][k]); // not buy and buy 
                    }else{ // can not buy
                        curr[0][k] = max(prices[i] + after[1][k-1], after[0][k]); // not sell and sell 
                    }
                    
                }
            }
            after = curr;
        }

        return after[1][2];
    }

    
};