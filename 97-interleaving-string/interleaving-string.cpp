// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int i = 0;
//         int j = 0;
//         int k = 0;
//         bool firstprio = true;
//         while(k < s3.length()){
//             // cout << "i: "<< i << " : " << s1[i] << endl;
//             // cout << "j: "<< j << " : " << s2[j] << endl;
//             // cout << "k: "<< k << " : " << s3[k] << endl;
//             // cout << "******" << endl;
//             if(firstprio){
//                 if(s3[k]==s1[i]){
//                     i++;
//                     firstprio = true;
//                 }
//                 else if(s3[k]==s2[j]){
//                     j++;
//                     firstprio = false;
//                 }else{
//                     return false;
//                 }
//             }else{
//                 if(s3[k]==s2[j]){
//                     j++;
//                     firstprio = false;
//                 }
//                 else if(s3[k]==s1[i]){
//                     i++;
//                     firstprio = true;
//                 }else{
//                     return false;
//                 }
//             }


//             k++;
            
//         }

//         // cout << "i: "<< i << endl;
//         // cout << "j: "<< j << endl;
//         // cout << "k: "<< k << endl;

//         if(i == s1.length() && j == s2.length() && k == s3.length()){
//             return true;
//         }

//         return false;
//     }
// };

bool rec(string s1, string s2, string s3, int i, int j, vector<vector<int>>& dp){
    // cout << s << endl;
    if(i == s1.length() && j == s2.length() && i+j == s3.length()){
        return dp[i][j] = true;
    }

    if( i+j >= s3.length() ){
        return dp[i][j] = false;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    bool result = false;
    if(i<s1.length()){
        if(s1[i] == s3[i+j]){
            result = rec(s1, s2, s3, i+1, j, dp);
        }
    }

    if(result == true){
        return dp[i][j] = result;
    }

    if(j<s2.length()){
        if(s2[j] == s3[i+j]){
            result = rec(s1, s2, s3, i, j+1, dp);
        }
    }

    return dp[i][j] = result;
}


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        if((s1.length() + s2.length()) != s3.length()){
            return false;
        }

        return rec(s1, s2, s3, 0, 0, dp);
    }
};