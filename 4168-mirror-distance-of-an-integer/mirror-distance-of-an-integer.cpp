class Solution {
public:
    int reversen(int n){
        int newn = 0;
        int r = 0;
        while(n > 0){
            r = n%10;
            newn = newn * 10 + r;
            n = n/10; 
        }
        return newn;
    }

    int mirrorDistance(int n) {
        return abs(n - reversen(n));
    }
};