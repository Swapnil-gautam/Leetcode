class Solution {
public:
    int findLHS(vector<int>& nums) {
        // unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());

        // for(int i = 0; i < nums.size(); i++){
        //     freq[nums[i]] = freq[nums[i]] + 1;
        // }

        // int i = 0;
        // int j = nums.size() - 1;

        // while(i < j){
        //     if((nums[j] - nums[i]) == 1){
        //         return (j - i + 1);
        //     }
        //     // if(abs(nums[i+1] - nums[i]) > abs(nums[j] - nums[j-1])){
        //     //     i = i+1;
        //     // }else{
        //     //     j = j - 1;
        //     // }

        //     if(freq[nums[i]] > freq[nums[j]]){
        //         j = j - freq[nums[j]];
        //     }else{
        //         i = i + freq[nums[i]];
        //     }
        // }

        int n = nums.size();

        if(n == 1){
            return 0;
        }

        int i = 0;
        int j = 0;
        int maxdiff = 0;
        
        // cout << "check check " << n << endl;
        while(i < n && j < n){
            
            // cout <<"nums[i]: " <<  nums[i] << endl;
            // cout <<"nums[j]: " << nums[j] << endl;
            // cout <<"maxdiff: " << maxdiff << endl; 

            if((nums[j] - nums[i]) == 1){
                if(maxdiff < (j - i + 1)){
                    maxdiff = (j - i + 1);
                } 
            }

            if(abs(nums[j] -  nums[i]) > 1){
                i = i + 1;
            }else{
                j = j + 1;
            }
        }

        return maxdiff;
    }
};