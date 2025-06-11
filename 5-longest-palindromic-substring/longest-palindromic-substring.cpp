// class Solution {
// public:

//     // bool isPal(string s){
//     //     string rev = s;
//     //     reverse(rev.begin(), rev.end());
//     //     if(rev == s){
//     //         return true;
//     //     }
//     //     else{
//     //         return false;
//     //     }
//     // }

//     // string rec(int i, string s, string curr, string& maxS){
//     //     if(i == s.length()){
//     //         return maxS;
//     //     }
//     //     cout << curr << endl;
//     //     if(isPal(curr) && (curr.length() > maxS.length()) ){
//     //         maxS = curr;
//     //     }
//     //     string take = rec(i+1, s, curr+s[i], maxS);
//     //     string nottake = rec(i+1, s, curr, maxS);
        
//     //     return maxS;

//     // }

//     // string longestPalindrome(string s) {
//     //     string curr = "";
//     //     string maxS = "";
//     //     return rec(0, s, curr, maxS);
//     // }

//     // string longestPalindrome(string s) {
//     //     int n = s.length();
//     //     string maxpal = "";
//     //     string t = "";
//     //     string rev = "";
//     //     for(int i = 0; i<n; i++){
//     //         for(int j = i;j<n; j++){
//     //             t = s.substr(i, n-j);
//     //             rev = t;
//     //             reverse(rev.begin(), rev.end());
//     //             if( (rev == t) && maxpal.length() < t.length()){
//     //                 maxpal = t;
//     //             }
//     //         }
//     //     }
//     //     return maxpal;
//     // }

//     int t[1001][1001];

//     bool checkpal(string s, int i, int j){
//         if(i >= j){
//             return 1;
//         }

//         if(t[i][j] != -1){
//             return t[i][j];
//         }
//         if(s[i] == s[j]){
//             i++;
//             j--;
//             return t[i][j] = checkpal(s, i, j);
//         }
//         return t[i][j] = 0;

//     }

//     string longestPalindrome(string s) {
//         int n = s.length();
//         // vector<vector<int>> dp(n, vector<int>(n,-1)); 
//         memset(t,-1,sizeof(t));
//         int maxLen = INT_MIN;
//         int sp = 0;
        

//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
                
//                 if(checkpal(s, i, j)){
//                     if(j-i+1 > maxLen){
//                         maxLen = j-i+1;
//                         sp = i;
//                     }
//                 }
//             }
//         }
        
//         return s.substr(sp, maxLen);
//     }
// };




class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int maxLen = 1;
        std::string maxStr = s.substr(0, 1);
        s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
        std::vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (i < right) {
                dp[i] = std::min(right - i, dp[2 * center - i]);
            }
            
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
                dp[i]++;
            }
            
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }
        
        return maxStr;
    }
};