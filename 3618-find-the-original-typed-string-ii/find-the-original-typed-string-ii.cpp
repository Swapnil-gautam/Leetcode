// This failed for ccnjuccc 646 / 846
// class Solution {
// public:
//     int count = 0;
//     void rec(string word, int k, int i, string curr, unordered_map<string, int>& check, char prevchar){
//         if(k <= 0){
//             // cout << curr << endl;
//             if(check[curr] == 0){
//                 // cout << curr << endl;
//                 check[curr]++;
//                 count = count + 1;
//                 // return 1;
//             }
//         }
//         if(i == word.length()){
//             return;
//         }

//         // cout << curr << endl;
//         // check[curr]++;

//         // int take = rec(word, k-1, i+1, curr+word[i], check);
//         // int not_take = rec(word, k, i+1, curr, check);

//         // if(prevchar != word[i]){
//         //     rec(word, k-1, i+1, curr+word[i], check, word[i]);
//         // }else{
//         //     rec(word, k-1, i+1, curr+word[i], check, word[i]);
//         //     rec(word, k, i+1, curr, check, word[i]);
//         // }

//         rec(word, k-1, i+1, curr+word[i], check, word[i]);
//         rec(word, k, i+1, curr, check, word[i]);


//         // return take+not_take;

//         return;
//     }
//     int possibleStringCount(string word, int k) {

//         string uniquechars = "";
//         string remainingchar = "";

//         char prevchartemp = word[0];
//         uniquechars = uniquechars + prevchartemp;
//         for(int i = 1; i < word.length(); i++){
//             if(prevchartemp != word[i]){
//                 uniquechars = uniquechars + word[i];
//             }else{
//                 remainingchar = remainingchar + word[i];
//             }

//             prevchartemp = word[i];
//         }

//         // cout << "uniquechars: " << uniquechars << endl;
//         // cout << "remainingchar: " << remainingchar << endl;
        
//         string curr = "";
//         char prevchar;
//         unordered_map<string, int> check;
//         // rec(word, k, 0, curr, check, prevchar);
//         rec(remainingchar, k-uniquechars.length(), 0, curr, check, prevchar);

//         return count;
//     }
// };


class Solution {
public:
    int M = 1e9+7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {

            vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }
                
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;
    }
};