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

                // int j = 0; 
                // while(j < 8){
                //     if(curr[j] != endGene[j]){
                //         string temp;
                //         temp = curr.substr(0,j) + endGene[j] + curr.substr(j+1,8-(j+1)); 
                //         cout << "*******" << endl;
                //         cout <<"0 to j: "<< curr.substr(0,j) << endl;
                //         cout <<"j: "<< endGene[j] << endl;
                //         cout <<"j to 8: "<< curr.substr(j+1,8-(j+1)) << endl;
                //         cout << "*******" << endl;
                //         cout <<"temp1: " << temp << endl;
                //         if(mp.find(temp)!=mp.end() && mp[temp] == 0){
                //             mp[temp] = 1;
                //             cout <<"temp2: " << temp << endl;
                //             qu.push(temp);
                //         }
                //     }
                //     j++;
                // }
                for(const auto& pair : mp){
                    // cout << pair.first << endl;
                    // cout << pair.second << endl;
                    string tempend = pair.first;

                    int j = 0; 
                    int diff = 0;
                    while(j < 8){
                        if(curr[j] != tempend[j]){
                            diff++;
                        }
                        j++;
                    }
                    
                    // cout << "diff: " << diff << endl;
                    if(diff == 1 && pair.second == 0){
                        mp[pair.first] = 1;
                        qu.push(pair.first);
                    }
                }

            }
            // cout << "%%%%%%%%%%%%%%%%%%" << endl;
            level = level+1;
        }

        return -1;
    }
};