class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        long mid;
        int res = 0;

        while(l <= r){
            mid = (l+r)/2;
            if(x < mid*mid){
                r = mid - 1;
            }else if(x > mid*mid){
                l = mid + 1;
                res = mid;
            }else{
                return mid;
            }
        }

        return res;
    }
};