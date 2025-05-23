class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;

        int mid;
        while(low <= high ){
            mid = (low + high)/2;
            if(target == nums[mid]){
                return mid;
            }


            if(nums[low] <= nums[mid]){
                if(target > nums[mid] || target < nums[low]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{
                if(target < nums[mid] || target > nums[high]){
                    high = mid - 1;
                    
                }else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};