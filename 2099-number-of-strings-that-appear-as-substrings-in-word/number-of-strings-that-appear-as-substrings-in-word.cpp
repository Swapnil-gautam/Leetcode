class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> substrs;

        for(int i = 0; i < word.length(); i++){
            for(int j = i; j < word.length(); j++){
                string s = word.substr(i, j-i+1);
                // cout << s << endl;
                substrs.insert(s);
            }
        }

        int count = 0;
        for(int i = 0; i < patterns.size(); i++){
            if(substrs.find(patterns[i]) != substrs.end()){
                count++;
            }
        }

        return count;
    }
};