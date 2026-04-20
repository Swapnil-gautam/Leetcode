class Solution {
public:
    int findpivot(vector<int>& nums){
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;

        while(l < r){
            while(l < r && nums[l] == nums[l+1]){
                l++;
            }
            while(l < r && nums[r] == nums[r-1]){
                r--;
            }
            mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    bool bs(vector<int>& nums, int l, int r, int& target){
        int mid = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                // cout << "nums[mid]: " << nums[mid] << " target: " << target << endl;
                return true;
            }
            if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {

        int pivot = findpivot(nums);
        // cout << "pivot: " << pivot << endl;
        if(bs(nums, 0, pivot-1, target) == true){
            return true;
        }
        return bs(nums, pivot, nums.size()-1, target);
        
    }
};