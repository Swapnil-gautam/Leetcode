class Solution {
public:

    unordered_set<string> words;
    int n;
    int t[301];

    bool solve(int idx, string& s){

        if(idx >= n){
            return true;
        }
        if(t[idx] != -1){
            return t[idx];
        }
        if(words.find(s) != words.end()){
            return true;
        }

        for(int l = 1; l <= n; l++){
            if((words.find(s.substr(idx, l)) != words.end()) && (solve(idx+l, s))){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));
        for(string &word : wordDict){
            words.insert(word);
        }

        return solve(0, s);
    }
};