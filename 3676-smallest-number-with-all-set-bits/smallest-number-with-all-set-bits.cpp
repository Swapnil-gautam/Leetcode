class Solution {
public:
    int smallestNumber(int n) {
        int t = 0;
        int res = 1;
        while(n > 0){
            n = n >> 1;
            res = res << 1;
            // t++;
        }
      
        // cout << "t: " << t << endl;
        // while(t > 0){
        //     res = res << 1;
        //     t = t-1;
        // }
        // bitset<32> binary_representation(n);
        // cout << "Binary:  " << binary_representation << endl;
        return res-1;
    }
};