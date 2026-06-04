// class Solution {
// public:
//     // int solve(unordered_map<int, int> dp, int curr, int num2, int res){
//     //     if(curr == num2+1){
//     //         return res;
//     //     }

//     // }

//     int check(int curr, unordered_map<int, int>& dp){
//         if(dp.find(curr) != dp.end()){
//             return dp[curr];
//         }

//         vector<int> digits;
//         int res = 0;
//         while(curr > 0){
//             if(dp.find(curr) != dp.end()){
//                 res = dp[curr];
//                 break;
//             }
//             int t = curr%10;
//             digits.insert(digits.begin(), t); 
//             curr = curr/10;
//         }


//     }

//     int totalWaviness(int num1, int num2) {
//         unordered_map<int, int> dp;
//         int res = 0;
//         // return solve(dp, num1, num2, res);
//         for(int i=num1; i < num2+1; i++){
//             res = res + check(num1, dp);
//         }
//         return res;
//     }
// };


class Solution {
public:
    int findWaiveScore(int num) {
        string s = to_string(num);

        int l = s.length();
        if (l < 3)
            return 0;

        int score = 0;
        for (int i = 1; i <= l - 2; i++) {
            // peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) score++;

            // valley
            if (s[i] < s[i - 1] && s[i] < s[i + 1]) score++;
        }

        return score;
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;

        for (int num = num1; num <= num2; num++) {
            score += findWaiveScore(num);
        }

        return score;
    }
};