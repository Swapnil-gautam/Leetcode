// class Solution {
// public:
//     bool solve(int n){

//         if(n%2 == 0){
//             if(n > 2){
//                 return solve(n/2);
//             }else{
//                 return true;
//             }
//         }else{
//             return false;
//         }
//     }
//     bool isPowerOfTwo(int n) {
//         if(n == 1){
//             return true;
//         }
//         if(n <= 0){
//             return false;
//         }
//         return solve(n);
//     }
// };


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        while(n > 1){
            // cout << n << endl;
            if(n & 1 != 0){
                return false;
            }
            n = n >> 1;
        }

        // cout << n << endl;
        if(n & 1 != 1){
            return false;
        }

        return true;
    }
};