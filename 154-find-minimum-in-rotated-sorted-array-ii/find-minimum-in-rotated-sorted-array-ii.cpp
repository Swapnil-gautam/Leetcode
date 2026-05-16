class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int r = n-1; // 3

        while(l < r){
            int mid = (l+r)/2; // 1
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else if(nums[mid] < nums[r]){
                r = mid;
            }else{
                int prevmid = mid;
                // cout << "mid: " << mid << endl;
                int lmid = mid;
                int rmid = mid;

                while(nums[mid] == nums[lmid] && lmid > l){
                    lmid = lmid-1;
                }

                while(nums[mid] == nums[rmid] && rmid < r){
                    rmid = rmid+1;
                }

                // cout << "lmid: " << lmid << " rmid: " << rmid << endl;

                if(nums[lmid] > nums[rmid]){
                    l = rmid;
                }else{
                    r = lmid;
                }
            }
        }

        return nums[l];
    }
};
