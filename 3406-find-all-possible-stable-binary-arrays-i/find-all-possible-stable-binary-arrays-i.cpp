// class Solution {
// public:
//     int LIMIT = 0;
//     const int MOD = 1e9+7;
//     int dp[201][201][201][2];

//     int solve(int zero, int one, int limit, int prev) {
//         if(zero == 0 && one == 0 ){
//             return 1;
//         }

//         if(dp[zero][one][limit][prev] != -1)
//             return dp[zero][one][limit][prev];
                
//         int take0 = 0;
//         int take1 = 0;

//         if(limit == 0){
//             if(prev == 0){
//                 if(one > 0)
//                     return dp[zero][one][limit][prev] =
//                         solve(zero, one-1, LIMIT, 1);
//                 return dp[zero][one][limit][prev] = 0;
//             }else{
//                 if(zero > 0)
//                     return dp[zero][one][limit][prev] =
//                         solve(zero-1, one, LIMIT, 0);
//                 return dp[zero][one][limit][prev] = 0;
//             }
//         }

//         if(zero > 0 ){

//             if(prev == 0){
//                 take0 = solve(zero-1,one,limit-1,0);
//             }else{
//                 take0 = solve(zero-1,one,LIMIT,0);
//             }
            
//         }

//         if(one > 0 ){
//             if(prev == 0){
//                 take1 = solve(zero, one-1, LIMIT,1);
//             }else{
//                 take1 = solve(zero, one-1, limit-1,1);
//             }
//         }

//         // return take0 + take1;
//         return dp[zero][one][limit][prev] = (take0 + take1) % MOD;
//     }

//     int numberOfStableArrays(int zero, int one, int limit) {
//         LIMIT = limit-1;
//         memset(dp,-1,sizeof(dp));
//         return (solve(zero-1, one, LIMIT, 0) + solve(zero, one-1, LIMIT, 1)) % MOD;
//     }
// };




class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if(onesLeft == 0 && zerosLeft == 0) {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
            return t[onesLeft][zerosLeft][lastWasOne];
        }


        int result = 0;

        if(lastWasOne == true) { //explore 0s
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { //explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;

    }
};