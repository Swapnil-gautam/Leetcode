class Solution {
public:
    double helper(double x, long n){
        if(n == 0 || x == 1.00){
            return 1.00;
        }
        if( x == 0){
            return 0;
        }
        double res = helper(x, n/2);
        res = res  * res;
        if(n%2){
            res = x * res;
        }
        return res;
    }

    double myPow(double x, int n) {
        double t = x;
        long np = n;
        double r ;
        if(n < 0){
            np = -np;
            t = 1.0/t;
            x = 1.0/x;
        }

        r = helper(t, np);

        return r;
    }


};