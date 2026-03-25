class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<long long> vert_back(n,0);
        vector<long long> hori_back(m,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vert_back[i] = vert_back[i] + grid[i][j];
                hori_back[j] = hori_back[j] + grid[i][j];
            }
        }

        vector<long long> vert_forw(vert_back);
        // for(int i = n-2; i >= 0; i--){
        //     vert_back[i] = vert_back[i] + vert_back[i+1];
        // }
        // vert_back[n-1] = 0;
        for(int i = 1; i < n; i++){
            vert_forw[i] = vert_forw[i] + vert_forw[i-1];
            vert_back[n-1-i] = vert_back[n-1-i] + vert_back[n-1-i+1];
        }
        vert_forw.insert(vert_forw.begin(), 0);
        vert_back.push_back(0);
        // vert_forw[0] = 0;
        for(int i = 0; i < n+1; i++){
            // cout << vert_forw[i] << " ";
            if(vert_forw[i] == vert_back[i]){
                return true;
            }
        }
        // cout << endl;

        vector<long long> hori_forw(hori_back);

        for(int i = 1; i < m; i++){
            hori_forw[i] = hori_forw[i] + hori_forw[i-1];
            hori_back[m-1-i] = hori_back[m-1-i] + hori_back[m-1-i+1];
        }
        hori_forw.insert(hori_forw.begin(), 0);
        hori_back.push_back(0);
        // vert_forw[0] = 0;
        for(int i = 0; i < m+1; i++){
            // cout << vert_forw[i] << " ";
            if(hori_forw[i] == hori_back[i]){
                return true;
            }
        }

        return false;

    }
};