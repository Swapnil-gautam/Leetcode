class Solution {
public:
    bool isSafe(int n, vector<string>& gride, int row, int col){
        for(int i = 0; i < n; i++){
            if(gride[i][col] == 'Q'){
                return false;
            }
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(gride[i][j] == 'Q') {
                return false;
            }
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(gride[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nqueen(int n, vector<vector<string>>& res, vector<string>& gride, int row){
        if(row == n){
            res.push_back(gride);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(n, gride, row, col)){
                gride[row][col] = 'Q';
                nqueen(n, res, gride, row+1);
                gride[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> gride(n, string(n, '.'));
        
        nqueen(n, res, gride, 0);
        return res;
    }
};
