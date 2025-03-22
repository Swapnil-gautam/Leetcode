class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;

        while(low <= high){
            int mid = (low + high)/2;
            cout <<"mid: " << mid << endl;
            if(nums[low] > nums[high]){

                if(nums[mid] > nums[low]){
                    low = mid;
                }else if(nums[mid] < nums[low]){
                    high = mid;
                }else{
                    if(nums[low] < nums[high]){
                        return nums[low];
                    }else{
                        return nums[high];
                    }
                }
            }else{
                return nums[low];
            }
        }

        return 0;
    }
};