class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1){
            return 0;
        }

        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(high - low > 1){
            
            mid = (low + high)/2;
            //cout << "1 mid " <<  mid <<  " h " <<  high <<  " l " <<  low << endl;  
            if(nums[mid] < nums[mid+1]){
                low = mid;
            }else{
                high = mid;
            }
            //cout << "2 mid " <<  mid <<  " h " <<  high <<  " l " <<  low << endl;  
        }

        if(nums[high]>nums[low]){
            return high;
        }else{
            return low;
        }
    }
};