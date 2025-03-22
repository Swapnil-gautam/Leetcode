class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int lowt = -1;
        int hight = -1;
        vector<int> res = {-1, -1};

        while(low <= high){

            mid = (low + high)/2;

            if(target < nums[mid]){
                high = mid-1;
            }else if(target > nums[mid]){
                low = mid+1;
            }else{
                hight = mid;
                low = mid+1;
            }
        }

        low = 0;
        high = nums.size()-1;

        while(low <= high){

            mid = (low + high)/2;

            if(target < nums[mid]){
                high = mid-1;
            }else if(target > nums[mid]){
                low = mid+1;
            }else{
                lowt = mid;
                high = mid-1;
            }
        }

        res[0] = lowt;
        res[1] = hight;

        return res;
    }
};