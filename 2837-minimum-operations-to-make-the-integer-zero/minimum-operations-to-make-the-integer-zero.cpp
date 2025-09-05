// class Solution {
// public:
//     // int makeTheIntegerZero(int num1, int num2) {
//     //     int j = 0;
//     //     while(num1 != 0){
//     //         int i = 0;
//     //         int prev = num1;
//     //         while( (pow(2, i)+num2) < num1 && (pow(2, i)+num2) < 0){
//     //             // cout << "pow:" << pow(2, i)+num2 << endl;
//     //             i = i+1;
//     //         }
//     //         if(i > 0){
//     //             i = i-1;
//     //         }
//     //         if((pow(2, i)+num2) == 0){
//     //             i=i+1;
//     //         }
//     //         cout << "pow final: "<< pow(2, i)+num2 << endl;

//     //         num1 = num1 - (pow(2, i)+num2);
//     //         if(abs(prev) < abs(num1)){
//     //             return -1;
//     //         }
//     //         j++;
//     //     }
//     //     return j;
//     // }

//     int makeTheIntegerZero(int num1, int num2) {
//         int j = 0;
//         // set<int> num1check;
//         while(num1 != 0){
//             int i = 0;
//             int prev = num1;
//             // int subpart = pow(2, i) + num2;
//             // while(subpart < 0 || subpart < num1){
//             //     subpart = pow(2, i) + num2;
//             //     cout << "subpart: "  <<  subpart <<  endl;
//             //     i++;
                
//             // }
//             while(abs(num1 - (pow(2, i+1) + num2)) < abs(num1 - (pow(2, i) + num2))){
//                 i++;
//             }
//             num1 = num1 - (pow(2, i) + num2);
//             cout << num1 << endl;
//             // if(num1check.find(num1) == num1check.end()){
//             //     num1check.insert(num1);
//             // }else{
//             //     return -1;
//             // }

//             if(abs(prev) < abs(num1)){
//                 return -1;
//             }
            
//             // return 0;
//             j++;
//         }
//         return j;
//     }
// };




/****************************************************** C++ **************************************************************/
//Approach-1 - Maths derivation
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;

        while(true) {
            long long val = (long long)num1 - (long long)t * num2;

            if(val < 0)
                return -1;
            
            if(__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }

            t++;
        }

        return -1;
    }
};