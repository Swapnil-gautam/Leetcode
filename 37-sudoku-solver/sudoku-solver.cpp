// class Solution {
// public:
//     void checkpossibleNum(int k,int l, vector<vector<char>>& board, vector<pair<int, int>> NumCanCome){
//         for(int i = 0; i < 3; i++){
//             for(int j = 0; j < 3; j++){
//                 if(board[i+k][j+l] == (num + '0')){
//                     return;
//                 }
//             }
//         }


//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         vector<vector<vector<char>>> canNotCome(9, vector<vector<char>>( 9, vector<char> (9,-1)));
            
//         for(int k = 0; k < 9; k=k+3){
//             for(int l = 0; l < 9; l=l+3){
//                 // for each num 1-9
//                 for(int num = 1; num <= 9; num++){

//                     // check in the box if there is only on position that it can come then place it
//                     vector<pair<int, int>> NumCanCome;
//                     checkNumpossibleplace(k,l,board, NumCanCome, num);
                    
//                     if(NumCanCome.size() == 1){
//                         board[i+k][j+l] = NumCanCome[0];
//                     }
//                 }
//             }
//         }

//         }
        

// };






/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), fixed frid size
//S.C : O(1), fixed grid size
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == d)
                return false;
            
            if(board[row][i] == d) {
                return false;
            }
        }

        int start_i = row/3 * 3;
        int start_j = col/3 * 3;

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                if(board[start_i+k][start_j+l] == d) {
                    return false;
                }
            }
        }

        return true;
    }

    //2^9
    //O(9 ^ 81)
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) { //O(9)
            for(int j = 0; j < 9; j++) { //O(9)
                if(board[i][j] == '.') {

                    for(char d = '1'; d <= '9'; d++) { 

                        if(isValid(board, i, j, d)) {
                            board[i][j] = d;

                            if(solve(board) == true) {
                                return true;
                            }

                            board[i][j] = '.';
                        }

                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
