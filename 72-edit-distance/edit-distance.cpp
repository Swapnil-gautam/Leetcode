using namespace std;

class Solution {
public:
    int rec(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){

        if(i < 0) return  j+1;
        if(j < 0) return  i+1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int del = 0;
        int rep = 0;
        int ins = 0;
        int res = 0;
        if(w1[i] != w2[j]){
            del = 1 + rec(w1, w2, i-1, j, dp); // delete
            rep = 1 + rec(w1, w2, i-1, j-1, dp); // replace
            ins = 1 + rec(w1, w2, i, j-1, dp); // insert

            res  = min(min(del, ins), rep);
            

        }else{
            res = rec(w1, w2, i-1, j-1, dp);
        }

        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return rec(word1, word2, n-1, m-1, dp);
    }
};