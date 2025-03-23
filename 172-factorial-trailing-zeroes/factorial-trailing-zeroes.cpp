class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        int temp = 1;
        while(n > 0){
            if(n%5 == 0){
                temp = n;
                while(temp%5 == 0){
                    fives = fives + 1;
                    temp = temp/5;
                }
            }
            //cout << n << " : " << fives << endl;
            n = n-1;
        }

        return fives;
    }
};