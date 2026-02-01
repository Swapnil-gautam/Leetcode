class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // int first = nums[0];
        // int second = nums[1];
        // int third = nums[2];
        // nums.erase(nums.begin());
        sort(nums.begin()+1, nums.end());

        // for(int i = 3; i < nums.size(); i++){
        //     second = min(nums[i], second);
        //     third = min(second, third);
        // }

        return nums[0] + nums[1] + nums[2];
    }
};