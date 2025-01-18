class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> mp;
        for(auto b:bank){
            mp[b]= 0;
        }
        queue<string> qu;
        qu.push(startGene);
        int level = 0;
        while(!qu.empty()){
            int size = qu.size();
            for(int i = 0; i < size; i++){
                string curr = qu.front();
                qu.pop();
                
                if(curr == endGene){
                    return level;
                }

                for(const auto& pair : mp){
                    int diff = 0;
                    for(int j=0; j < 8; j++){
                        if(curr[j] != pair.first[j]){
                            diff++;
                        }
                    }
                    if(diff == 1 && pair.second == 0){
                        mp[pair.first] = 1;
                        qu.push(pair.first);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};