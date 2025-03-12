class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        int pos = 0;
        
        // // for(int i = 0; i < nums.size(); i ++){
        // //     if(nums[i] < 0){
        // //         neg = neg + 1;
        // //     }
        // //     if(nums[i]>0){
        // //         pos = pos + 1;
        // //     }
        // // }

        int i = 0;
        while(i < nums.size() && nums[i]<=0){
            if(nums[i]<0){
                neg++;
            }
            i++;
        }
        pos = nums.size() - i;

        return max(pos, neg);
    }

};