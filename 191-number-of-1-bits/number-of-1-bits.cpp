class Solution {
public:
    int hammingWeight(int n) {
        // cout << 1%2 << endl;
        int count = 0;
        while(n > 0){
            if(n%2 == 1){
                count = count + 1;
            }
            n = n/2;
        }
        return count;
    }
};