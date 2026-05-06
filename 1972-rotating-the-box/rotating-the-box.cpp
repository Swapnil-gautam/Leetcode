class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        // vector<int> space;
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<pair<int,int>>> sns(m);
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for(int i = 0; i < m; i++){
            int stonecount = 0;
            int spacecount = 0;
            for(int j = 0; j < n; j++){
                if(boxGrid[i][j] == '#'){
                    stonecount++;
                }else if(boxGrid[i][j] == '.'){
                    spacecount++;
                }else{
                    sns[i].push_back({stonecount, j});
                    stonecount = 0;
                    spacecount = 0;
                    // break;
                }
            }
            sns[i].push_back({stonecount, n});
        }

        for(int i = 0; i < sns.size(); i++){
            for(int j = 0; j < sns[i].size(); j++){
                // cout<< sns[i][j].first << " i: " << i << " j: "<< sns[i][j].second << " ";
                int newj = m-1-i;
                int newi = sns[i][j].second;
                if(newi != n){
                    res[newi][newj] = '*';
                }
                int stones = sns[i][j].first;
                while(stones > 0){
                    newi--;
                    res[newi][newj] = '#';
                    stones--;
                }

            }
            cout << endl;
        }
        return res;
    }
};