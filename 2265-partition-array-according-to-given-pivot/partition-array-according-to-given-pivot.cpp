class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lp;
        vector<int> p;
        vector<int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                lp.push_back(nums[i]);
            }else if( nums[i] > pivot){
                mp.push_back(nums[i]);
            }else{
                p.push_back(nums[i]);
            }
        }

        for(int i = 0; i < p.size(); i++){
            lp.push_back(p[i]);
        }
        for(int i = 0; i < mp.size(); i++){
            lp.push_back(mp[i]);
        }

        return lp;
    }
};