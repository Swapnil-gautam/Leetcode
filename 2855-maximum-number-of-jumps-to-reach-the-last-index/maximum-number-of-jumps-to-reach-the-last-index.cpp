class Solution {
public:
    int solve(vector<int>& nums, int target, int i, vector<int>& memo){
        if(i == nums.size()-1){
            return 0;
        }
        if(memo[i] != INT_MIN){
            return memo[i];
        }
        int res = -1;
        int temp = -1;
        for(int j = i+1; j < nums.size(); j++){
            if(abs(nums[j] - nums[i]) <= target){
                temp = solve(nums, target, j, memo);
                // memo[j] = temp;
                if( temp > -1){
                    res = max(res, 1+temp);
                }
            }
        }
        // cout << "i: " << i << " res: " << res << endl;
        return memo[i] = res;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n+1, INT_MIN);
        return solve(nums, target, 0, memo);
    }
};