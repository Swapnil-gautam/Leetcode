class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // even - odd = odd 
        // odd - odd = even
        // even - even = even
        // odd - even = odd

        int minnum = INT_MAX;
        int secminnum = INT_MAX;
        int evencount = 0;
        int oddcount = 0;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 0){
                evencount++;
            }else{
                oddcount++;
            }


            if(nums1[i] < minnum){
                secminnum = minnum;
                minnum = nums1[i];
            }
        }

        if(evencount == nums1.size() || oddcount == nums1.size()){
            return true;
        }

        if(minnum % 2 == 0){
            return false;
        }else{
            if(secminnum - minnum < 1){
                return false;
            }
        }

        return true;
    }
};