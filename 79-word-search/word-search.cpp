class Solution {
public:
    bool checkwords(vector<vector<char>>& board, string word, string& curr, int row, int col, int i){
        curr.push_back(board[row][col]);

        if(curr == word){
            //cout << "true called" << endl;
            return true;
        }

        //cout << row << " " << col << " " << board[row][col] << " " << word[i] << " " << curr << endl;
        bool r = false;
        bool l = false;
        bool t = false;
        bool b = false;

        
        char temp = board[row][col];
        board[row][col] = 0;
        if(i < word.size() && temp == word[i]){
            if(row-1>=0){
                //cout <<"row-1 " << board[row-1][col] << endl;
                t = checkwords(board, word, curr, row-1, col, i+1);
            }
            if(row+1<board.size()){
                //cout <<"row+1 " << board[row+1][col] << endl;
                b = checkwords(board, word, curr, row+1, col, i+1);
            }
            if(col-1>=0){
                //cout <<"col-1 " << board[row][col-1] << endl;
                l = checkwords(board, word, curr, row, col-1, i+1);
            }
            if(col+1<board[0].size()){
                //cout <<"col+1 " << board[row][col+1] << endl;
                r = checkwords(board, word, curr, row, col+1, i+1);
            }
        }
        board[row][col] = temp;
        curr.pop_back();
        // cout << "************"  << endl;
        // cout << (l || r || t || b) << endl;
        return (l || r || t || b);
    }

    bool exist(vector<vector<char>>& board, string word) {
        string curr;
        bool res = false;
        int i = 0;

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                // cout << "****" << endl;
                res = checkwords(board, word, curr, row, col, i);
                if (res == true){
                    return true;
                }
            }
        }

        return res;
    }
};