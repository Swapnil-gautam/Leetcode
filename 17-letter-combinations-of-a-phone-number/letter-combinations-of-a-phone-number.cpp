class Solution {
public:

    vector<string> ans;

    void backtracing(string digits, vector<string> mapping, int i, string& curr) {
        //cout << "curr.size(): " << curr.size() << " digits.size(): " << digits.size() << endl;
        if(curr.size() == digits.size()){
            ans.push_back(curr);
            //cout << "return" << endl;
            return;
        }
        
        int t = digits[i] - '0';
        for(int j = 0; j < mapping[t].size(); j++){
            string temp = curr;
            curr = curr + mapping[t][j];
            cout << curr << endl;
            backtracing(digits, mapping, i+1, curr);
            curr = temp;
        }
        //return ans;
    }

    vector<string> letterCombinations(string digits) {

        string curr = "";
        vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // cout << mapping[2] << endl;
        
        // for(int i = 0; i < digits.size(); i++){
        //     int t = digits[i] - '0';
        //     cout << mapping[t] << endl;
        //     for(int j = 0; j < mapping[t].size(); j++){
        //         cout << mapping[t][j] << endl;
        //     }
        // }
        if(digits.size() > 0){
            backtracing(digits, mapping, 0, curr);
        }else{
            return {};
        }

        return ans;
    }
};