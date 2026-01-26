class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = i + k - 1;
        int mindiff = INT_MAX;

        while(j < nums.size()){
            mindiff = min(mindiff, (nums[j] - nums[i]) );
            i++;
            j++;
        }
        return mindiff;
    }
};