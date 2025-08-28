class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagmap;
        vector<vector<int>> sorted_grid(n, vector<int>(n,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                diagmap[i-j].push_back(grid[i][j]);
            }
        }

        for(const auto& m : diagmap){
            // cout << "i - j: " << m.first << endl;
            vector<int> temp = m.second;
            if(m.first >= 0){
                sort(temp.begin(), temp.end());
            }else{
                sort(temp.begin(), temp.end(), greater<int>());
            }
            diagmap[m.first] = temp;
            // cout << "**************" << endl;
            // for(auto t: m.second){
            //     cout << t << endl;
            // }
            // cout << "**************" << endl;

        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sorted_grid[i][j] = diagmap[i-j][diagmap[i-j].size()-1];
                diagmap[i-j].pop_back();
            }
        }


        return sorted_grid;
    }
};