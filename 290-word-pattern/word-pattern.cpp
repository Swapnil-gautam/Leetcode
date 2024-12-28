class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapp;
        unordered_map<string, char> maps;
        s = s+" ";

        int i = 0;
        int j = 0;
        int p = 0;

        while(j < s.length()){
            if(s[j] == ' '){
                string word = s.substr(i, j-i);
                i = j+1;
                if(maps.find(word)==maps.end()){
                    maps[word] = pattern[p];
                }else{
                    if(maps[word] != pattern[p]){
                        return false;
                    }
                }

                if(mapp.find(pattern[p])==mapp.end()){
                    mapp[pattern[p]] = word;
                }else{
                    if(mapp[pattern[p]] != word){
                        return false;
                    }
                }
                //cout << word << " : "<< pattern[p] << " : " << p << endl;
                if(p == pattern.length()){
                    return false;
                }
                p++;
            }
            j++;
        }

        if(p < pattern.length()){
            return false;
        }
        
        return true;
    }
};