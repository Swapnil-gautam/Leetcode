// class Solution {
// public:
//     int solve(vector<int>& nums, int r, int i, int j, int k){
//         if(i == nums.size()){
//             return 0;
//         }

//         if(j == nums.size()){
//             // i = i+1;
//             // j = i+1;
//             // return solve(nums, r, i, j, k);
//             return 0; 
//         }
//         if((nums[i] + nums[j])%k == r){ 
//             //cout << " i: " << i << " j: " << j << endl;
//             i = j;
//             j = i+1;

//             return 1 + solve(nums, r, i, j, k);
//         }else{
//             j = j+1;
//             return solve(nums, r, i, j, k);
//         }
//     }

//     int maximumLength(vector<int>& nums, int k) {
//         int rmax = 0;
//         int max = 0;
//         for(int r = 0; r < k; r++){
//             for(int i = 0; i < nums.size(); i++){
//                 int j = i+1;
//                 rmax = solve(nums, r, i, j, k);
//                 //cout << "r: " << r << " " << rmax << endl;
//                 if(rmax > max){
//                     max = rmax;
//                 }
//             }
//         }

//         if(max > 0){
//             return max+1;
//         }

//         return max;
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //Using same LIS bottom up code

        int n = nums.size();
        
        //vector<int> dp1(n, 1); //mod1
        //vector<int> dp0(n, 1); //mod0
        // dp0 {} //mod0
        // dp1 {} //mod1
        //{
          //  {}, 0th row for mod0
           // {}  1st row for mod1         
        //}

        //row = 0 is for mod0
        //row = 1 is for mod1
        //row = 2 is for mod2
        //....
        //row = k-1 is for mod k-1
        vector<vector<int>> dp(k, vector<int>(n, 1));
        int maxSub = 1;

        //mod = 1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;
                //mod = 0 = 0th row , %2 = 0 waale case ka result
                //mod = 1 = 1st row, %2 = 1 waale case ka result
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }


        return maxSub;
    }
};