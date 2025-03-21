class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int res = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i]<target){
        //         res++;
        //     }else{
        //         break;
        //     }
        // }

        int low = 0;
        int high = nums.size();
        int mid;

        if(target > nums[high-1]){
            return high;
        }

        while(low <= high){
            mid = (low + high)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(target < nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        

        return low;
    }
};