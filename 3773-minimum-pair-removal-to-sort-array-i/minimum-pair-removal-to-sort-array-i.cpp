class Solution {
public:
    bool check_sorted(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            
            if(nums[i] > nums[i+1]){
                return false;
            }
        }

        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        
        // vector<int> res;
        int count = 0;
        
        while(check_sorted(nums) != true){
            count++;
            int minsum = INT_MAX;
            int update_i = -1;
            int n = nums.size();
            for(int i = 0; i < n-1; i++){
                // cout << nums[i]  << " ";
                if(nums[i]+nums[i+1] < minsum){
                    minsum = nums[i]+nums[i+1];
                    update_i = i;
                }
            }
            // cout << endl;
            // cout << "minsum: " << minsum << " update_i: "<< update_i << endl;
            nums[update_i] = minsum;
            nums.erase(nums.begin()+update_i+1);
        }

        return count;
    }
};