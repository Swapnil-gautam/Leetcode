class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        

        for(int i = 0; i < board.size(); i++){
            set<int> r;
            set<int> c;
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    if(!r.contains(board[i][j])){
                        r.insert(board[i][j]);
                    }else{
                        // cout << "i: " << i << " j: " << j << endl;
                        return false;
                    }
                }

                if(board[j][i] != '.'){
                    if(!c.contains(board[j][i])){
                        c.insert(board[j][i]);
                    }else{
                        // cout << "i: " << i << " j: " << j << endl;
                        return false;
                    }
                }
            }
        }


        for(int k = 0; k < 9; k=k+3){
            for(int l = 0; l < 9; l=l+3){
                set<int> b;

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        // cout << "i+k: " << i+k << " j+l: " << j+l << endl;
                        if(board[i+k][j+l] != '.'){
                            if(!b.contains(board[i+k][j+l])){
                                b.insert(board[i+k][j+l]);
                            }else{
                                // cout << "i: " << i << " j: " << j << endl;
                                return false;
                            }
                        }
                    }
                }

                // cout << "**********************" << endl;
            }
        }
        

        return true;
    }
};