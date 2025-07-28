class Solution {
public:
    int count = 0;
    void solve(vector<int>& nums, int maxbitwiseor, int i, int curr ){
        if(i == nums.size()){
            return;
        }

        int newor = curr | nums[i];
        if(newor == maxbitwiseor){
            count = count + 1;
        }
        solve(nums, maxbitwiseor, i+1, newor);
        solve(nums, maxbitwiseor, i+1, curr); 

        // return count;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxbitwiseor = 0;
        for(auto n: nums){
            maxbitwiseor = maxbitwiseor | n;
        }

        // cout << "maxbitwiseor: " << maxbitwiseor << endl;

        solve(nums, maxbitwiseor, 0, 0); 

        return count;
    }
};