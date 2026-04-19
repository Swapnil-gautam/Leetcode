class Solution {
public:

    int bs(vector<int>& nums1, int tar, int j){
        int l = 0; 
        int r = j;
        int mid = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(nums1[mid] > tar){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int res = 0;
        int i = 0;
        int t = 0;
        for(int j = 0; j < m; j++){
            if(nums1[t] <= nums2[j]){
                i = bs(nums1, nums2[j], t);
                res = max(res, j-i);
            }

            if(t < nums1.size()-1){
                t++;
            }
        }
        return res;
    }
};