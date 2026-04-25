// class Solution {
// public:
//     vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
//     }
// };

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> res;
        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < dictionary.size(); j++){
                int edits = 0;
                for(int k = 0; k < queries[i].size(); k++){
                    if(queries[i][k] != dictionary[j][k]){
                        edits++;
                    }
                    if(edits > 2){
                        break;
                    }
                }
                if(edits <= 2){
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};
