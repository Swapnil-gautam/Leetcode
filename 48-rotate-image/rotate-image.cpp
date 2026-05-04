class Solution {
public:

    void diagonal(vector<vector<int>>& matrix){

        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j <n; j++){
                if(i != j){
                    // cout << "start " << "matrix[i][j]: " << matrix[i][j] << " matrix[j][i]: " << matrix[j][i] << endl;
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                    // cout << "end " << "matrix[i][j]: " << matrix[i][j] << " matrix[j][i]: " << matrix[j][i] << endl;
                }
            }
        }
    }

    void upsidedown(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            vector<int> temp = matrix[i];
            matrix[i] = matrix[n-1-i];
            matrix[n-1-i] = temp;
        }
        diagonal(matrix);
    }

    void rotate(vector<vector<int>>& matrix) {
        upsidedown(matrix);
        
    }
};