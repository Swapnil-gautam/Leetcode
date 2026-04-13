class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minres = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                minres = min(abs(i-start), minres);
            }
        }
        return minres;
    }
};