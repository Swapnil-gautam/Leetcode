class Solution {
public:
    int findsmallest(vector<int>& nums){
        int l = 0; 
        int r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = findsmallest(nums);
        // cout <<"s: " << s << endl;
        if(target == nums[s]){
            return s;
        }
        if(target == nums[n-1]){
            return n-1;
        }
        if(target == nums[0]){
            return 0;
        }

        if( target > nums[n-1]){
            int l = 0;
            int r = s-1;
            // cout << "this is called 0" << "l: " << l << " r: " << r << endl;
            while(l <= r){
                int mid = (l+r)/2;
                if( nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }else{
            int l = s;
            int r = n-1;
            // cout << "this is called " << "l: " << l << " r: " << r << endl;
            while(l <= r){
                int mid = (l+r)/2;
                if( nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }

        return -1;
    }
};