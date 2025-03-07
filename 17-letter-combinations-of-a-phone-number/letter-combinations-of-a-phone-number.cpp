class Solution {
public:
    void backtrack(string digits, vector<string> digiToAlpha, vector<string>& res, string& curr){
        if(digits.size() == curr.size()){
            res.push_back(curr);
            return;
        }

        string t = digiToAlpha[(digits[curr.size()] - '0') - 2];
        for(int i = 0; i < t.size(); i++){
            // cout << t[i] << endl;
            curr.push_back(t[i]);
            backtrack(digits, digiToAlpha, res, curr);
            curr.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> digiToAlpha = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string curr;
        if(digits.size() != 0){
            backtrack(digits, digiToAlpha, res, curr);
        }else{
            return res;
        }

        return res;
    }
};