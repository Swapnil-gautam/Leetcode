class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int lsum = 0;
        vector<int> ls;
        for(int i = 0; i < nums.size(); i++){
            ls.push_back(lsum);
            lsum += nums[i];
        }

        int rsum = 0;
        vector<int> rs;
        for(int i = nums.size()-1; i >= 0; i--){
            // int t = abs(ls[i] - rsum);
            ls[i] = abs(ls[i] - rsum);
            rsum += nums[i];
        }

        return ls;
    }
};