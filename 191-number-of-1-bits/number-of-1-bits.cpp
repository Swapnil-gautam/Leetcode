class Solution {
public:
    int hammingWeight(int n) {
        // cout << 1%2 << endl;
        int count = 0;
        // while(n > 0){
        //     if(n%2 == 1){
        //         count = count + 1;
        //     }
        //     n = n/2;
        // }

        while(n != 0){
            if(n&1 == 1){ // if last bit is 1
                count = count + 1;
            }
            // n = n/2;
            n = n >> 1;
        }


        return count;
    }
};