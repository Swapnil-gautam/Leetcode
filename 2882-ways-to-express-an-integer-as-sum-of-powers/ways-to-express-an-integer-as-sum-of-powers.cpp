class Solution {
public:
    int Mod = 1000000007;
    int solve(int n, int x, int curr, vector<vector<int>>& memo){
        // cout << "num: " << num << " curr: " << curr << " x: " << x << endl;
        if(n == 0){
            // cout << "****** 1 **********" << endl;
            return  1;
        }else if(n < 0 || curr > n){
            return  0;
        }
        
        if(memo[curr][n] != -1){
            return memo[curr][n];
        }
        // long long power = pow(curr, x);
        // cout << "power: " << power << endl;
        if(pow(curr, x) > n){
            return 0;
        }

        int take = solve(n - pow(curr, x), x, curr+1, memo); 
        int nottake = solve(n, x, curr+1, memo); 

        return memo[curr][n] = (take + nottake)%Mod;

    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>memo(n+1, vector<int>(n+1, -1));
        return solve(n, x, 1, memo); 
    }
};

