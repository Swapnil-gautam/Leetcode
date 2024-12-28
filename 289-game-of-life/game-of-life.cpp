class Solution {
public:
    bool checkij(int i, int j, int row, int col){
        if(i>=0 && j>=0 && i<row && j<col){
            return true;
        }
        return false;
    }

    int neighborCount(vector<vector<int>> board, int i, int j){
        int ncount = 0;
        int row = board.size();
        int col = board[0].size();

        for(int l = -1; l<2; l++){
            for(int m = -1; m<2; m++){
                if(l==0 && m==0){
                    continue;
                }

                if(checkij(i+l, j+m, row, col) && board[i+l][j+m] == 1){
                    ncount++;
                }
            }
        }
        return ncount;
    }


    void gameOfLife(vector<vector<int>>& board) {
        vector<int> changei;
        vector<int> changej;
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                int nc = neighborCount(board, i, j);
                if(board[i][j] == 1){
                    if(nc<2){
                        changei.push_back(i);
                        changej.push_back(j);
                    }
                    if(nc>3){
                        changei.push_back(i);
                        changej.push_back(j);
                    }
                }else{
                    if(nc==3){
                        changei.push_back(i);
                        changej.push_back(j);
                    }
                }
            }
        }

        for(int t = 0; t < changei.size(); t++){
            if(board[changei[t]][changej[t]] == 1){
                board[changei[t]][changej[t]] = 0;
            }else{
                board[changei[t]][changej[t]] = 1;
            }
        }
    }
};