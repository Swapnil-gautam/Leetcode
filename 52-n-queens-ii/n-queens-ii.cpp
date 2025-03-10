class Solution {
public:
    bool isSafe(int n, vector<string> grid, int row, int col){

        //cout << "checking for row: " << row << " col: " << col << endl;

        for(int i = 0; i < n; i++){
            if(grid[i][col] == 'Q'){
                //cout << "found a queen in same col" << " i: " << i << " col: " << col <<  endl;
                return false;
            }
        }

        int i = row;
        int j = col;
        while(i >= 0 && j >= 0){
            if(grid[i][j] == 'Q'){
                //cout << "found a queen in right upper" << " i: " << i << " j: " << j <<  endl;
                return false;
            }
            i = i-1;
            j = j-1;
        }

        i = row;
        j = col;
        while(i < n && j < n){
            if(grid[i][j] == 'Q'){
                //cout << "found a queen in left bottom" << " i: " << i << " j: " << j <<  endl;
                return false;
            }
            i = i+1;
            j = j+1;
        }

        i = row;
        j = col;
        while(i < n && j >= 0){
            if(grid[i][j] == 'Q'){
                //cout << "found a queen in right lower" << " i: " << i << " j: " << j <<  endl;
                return false;
            }
            i = i+1;
            j = j-1;
        }

        i = row;
        j = col;
        while(i >= 0 && j < n){
            if(grid[i][j] == 'Q'){
                //cout << "found a queen in left upper" << " i: " << i << " j: " << j <<  endl;
                return false;
            }
            i = i-1;
            j = j+1;
        }

        return true;
    }

    void nqueen(int n, vector<string> grid, int& count, int row){
        if(row == n){
            count = count + 1;
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(n, grid, row, col)){
                //cout << "row: " << row << " col: " << col << endl;
                grid[row][col] = 'Q';
                nqueen(n, grid, count, row+1);
                grid[row][col] = '.';
            }
        }
        return;
    }

    int totalNQueens(int n) {
        int count = 0;
        int row = 0;
        vector<string> grid(n , string(n, '.'));
        nqueen(n, grid, count, row);
        return count;
    }
};