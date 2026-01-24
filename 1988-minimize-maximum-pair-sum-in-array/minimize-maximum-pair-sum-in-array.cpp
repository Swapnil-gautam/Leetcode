class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        for(int i = 0; i < (n/2); i++){
            // cout << "nums[i]: " << nums[i] << endl;
            res = max(res, nums[i]+nums[n-1-i]);
        }
        // int i = n/2;
        // cout << i << nums[i] << endl;
        return res; 
    }
};