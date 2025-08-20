class Solution {
public:
    int checknextlayer(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& t){
        if(i >= m || j >= n ){
            return 0;
        }
        if(matrix[i][j] == 0){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        int right = checknextlayer(matrix, i+1, j, m, n, t);
        int down = checknextlayer(matrix, i, j+1, m, n, t);
        int diag = checknextlayer(matrix, i+1, j+1, m, n, t);

        return t[i][j] = 1+ min(min(right, down), diag);
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // stack<pair<int, int>> checkthem;
        int sqrnum = 0;
        // cout << "m: " << m << endl;
        // cout << "n: " << n << endl;
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    sqrnum += checknextlayer(matrix, i, j, m, n, t);
                }
            }
        }

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return sqrnum;
    }
};