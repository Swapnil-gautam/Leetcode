class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, int> mapi;
        int j = 0;
        for(int i=0; i< strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());

            if(mapi.find(word) == mapi.end()){
                
                vector<string> temp;
                temp.push_back(strs[i]);
                res.push_back(temp);

                mapi[word] = j;
                j++;
                //cout << "i: " << i << " j: " << j << " w: " << word << " mp[w]: " << mapi[word] << endl;
            }else{
                //cout << "i: " << i << " j: " << j << " w: " << word << " mp[w]: " << mapi[word] << endl;
                res[mapi[word]].push_back(strs[i]);
            }
            // cout << word << endl;
        }

        return res;
    }
};