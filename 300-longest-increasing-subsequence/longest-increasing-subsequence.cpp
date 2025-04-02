class Solution {
public:
    // int solve(vector<int>& nums, int i, int res, vector<int>& dp, int& maxres){
    //     if(i == nums.size()-1){
    //         return maxres;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     for(int j = i+1; j < nums.size(); j++){
    //         cout << "i: " << i << " : " << nums[i] << " , j: " << j << " : " << nums[j] <<  " res: " << res << endl;
    //         if(nums[i] < nums[j]){
    //             solve(nums, j, res+1, dp, maxres);
    //         }
    //     }
    //     cout << "dp[i] i:" << i << " res: " << res << endl;
    //     maxres = max(maxres, res);
    //     return dp[i] = maxres;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(), -1);
    //     int res = 1;
    //     int maxres = 1;
    //     for(int i = 0; i < nums.size(); i++){
    //         solve(nums, i, res, dp, maxres);
    //     }
    //     return maxres;
    // }

    int n;
    int t[2501][2501];
    int solve(vector<int>& nums, int i, int P){

        if(i >=n ){
            return 0;
        }
        if(P != -1 && t[i][P] != -1){
            return t[i][P];
        }

        int take = 0;

        if(P == -1 || nums[i] > nums[P]){
            take = 1+solve(nums, i+1, i);
        }

        int skip = solve(nums, i+1, P);

        if(P!=-1){
            t[i][P] = max(take, skip);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        memset(t, -1, sizeof(t));

        return solve(nums, 0, -1);
    }
};