class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> feelbad;

        for(int i = 0; i < friendships.size(); i++){
            int u = friendships[i][0];
            int v = friendships[i][1];

            bool allgood = false;

            // cout << "******************" << endl;

            for(int j = 0; j < languages[u-1].size(); j++){
                // cout << "u: " << u << " " << languages[u-1][j] << endl;
                for(int k = 0; k < languages[v-1].size(); k++){
                    // cout << "v: " << v << " " << languages[v-1][k] << endl;
                    if(languages[u-1][j] == languages[v-1][k]){
                        allgood = true;
                    }
                }
            } 

            if(allgood == false){
                feelbad.insert(u);
                feelbad.insert(v);
            }
        }

        // while(!feelbad.empty()){
        //     cout << feelbad.top() << endl;
        //     feelbad.pop()
        // }

        vector<int> maxusedLanguage(n,0);

        // cout << "*********" << endl;

        for (auto it = feelbad.begin(); it != feelbad.end(); ++it) {
            int p = *it;
            // cout << "p: " << p << endl;
            for(int i = 0; i < languages[p-1].size(); i++){
                // cout << "i: " << languages[p-1][i] << endl;
                maxusedLanguage[languages[p-1][i]-1]++;
            }
            // cout << *it << " ";
        }

        // cout << "*********" << endl;
        int maxlangcount = 0;
        for(int i = 0; i < maxusedLanguage.size(); i++){
            cout << maxusedLanguage[i] << endl;
            if (maxlangcount < maxusedLanguage[i]){
                maxlangcount = maxusedLanguage[i];
            }
        }

        return feelbad.size() -  maxlangcount;
    }
};