class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // unordered_map<int, int> zeroi;
        // unordered_map<int, int> zeroj;
        // int m = matrix.size();
        // int n = matrix[0].size();

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(matrix[i][j] == 0){
        //             zeroi[i] = 1;
        //             zeroj[j] = 1;
        //         }
        //     }
        // }

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(zeroi.find(i)!=zeroi.end() || zeroj.find(j)!=zeroj.end()){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }


        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrowhaszero = false;
        bool firstcolhaszero = false;

        for(int j = 0; j<n; j++){
            if(matrix[0][j] == 0){
                firstrowhaszero = true;
                break;
            }
        }

        for(int i = 0; i<m; i++){
            if(matrix[i][0] == 0){
                firstcolhaszero = true;
                break;
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrowhaszero){
            for(int j = 0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        if(firstcolhaszero){
            for(int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};