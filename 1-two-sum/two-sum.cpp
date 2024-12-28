class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        // for(int i = 0; i < nums.size(); i++){
        //     map[nums[i]] = i;
        // }

        for(int i = 0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end() && map[(target - nums[i])] != i){
                res.push_back(i);
                res.push_back(map[(target - nums[i])]);
                break;
            }
            map[nums[i]] = i;
        }

        return res;
    }
};