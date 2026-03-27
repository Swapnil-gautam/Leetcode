class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k%m;
        // vector<vector<int>> resmat;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            if(i%2 == 0){
                for(int j = k; j < m; j++){
                    temp.push_back(mat[i][j]);
                    // cout << mat[i][j] << " ";
                }
                for(int j = 0; j < k; j++){
                    temp.push_back(mat[i][j]);
                    // cout << mat[i][j] << " ";
                }
            }else{
                for(int j = m-k; j < m; j++){
                    temp.push_back(mat[i][j]);
                    // cout << mat[i][j] << " ";
                }
                for(int j = 0; j < m-k; j++){
                    temp.push_back(mat[i][j]);
                    // cout << mat[i][j] << " ";
                }
            }

            for(int j = 0; j < m; j++){
                if(mat[i][j] != temp[j]){
                    return false;
                }
            }

            // resmat.push_back(temp);
        }

        return true;
    }
};