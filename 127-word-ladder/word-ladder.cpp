class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        queue<string>  qu;

        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]] = 0;
        }

        qu.push(beginWord);
        int level = 1;

        while(!qu.empty()){
            int size = qu.size();
            for(int i = 0; i < size; i++){
                string curr = qu.front();
                qu.pop();
                // cout << curr << endl;
                if(curr == endWord){
                    return level;
                }
                
                for(const auto& w: mp){
                    if(w.second == 0){
                        int diff = 0;
                        for(int j = 0; j < curr.length(); j++){
                            if(curr[j] != w.first[j]){
                                diff++;
                            }
                        }
                        if(diff == 1){
                            mp[w.first] = 1; 
                            qu.push(w.first);
                        }
                    }
                }
            }
            level++;
            // cout << "****  " << level << endl;
        }

        return 0;
    }
};