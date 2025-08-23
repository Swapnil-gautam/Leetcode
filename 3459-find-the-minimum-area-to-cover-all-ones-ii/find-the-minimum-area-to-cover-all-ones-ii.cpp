class Solution {
public:
    int minArea(int minX, int minY, int maxX, int maxY, vector<vector<int>>& grid){
        int curr_minX = grid.size();
        int curr_minY = grid[0].size();
        int curr_maxX = -1;
        int curr_maxY = -1;

        for(int i = minX; i < maxX; i ++){
            for(int j = minY; j < maxY; j++){
                if(grid[i][j] == 1){
                    if(curr_minX > i){
                        curr_minX = i;
                    }
                    if(curr_minY > j){
                        curr_minY = j;
                    }
                    if(curr_maxX < i){
                        curr_maxX = i;
                    }
                    if(curr_maxY < j){
                        curr_maxY = j;
                    }
                }
            }
        }
        return (((curr_maxX - curr_minX)+1) * ((curr_maxY - curr_minY)+1));
    };

    int util(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MAX;
        for(int rowsplit = 1; rowsplit < m; rowsplit++){
            for(int colsplit = 1; colsplit < n; colsplit++){

                int top = minArea(0,0,rowsplit,n,grid);
                int bottomright = minArea(rowsplit,0,m,colsplit,grid);
                int bottomleft = minArea(rowsplit,colsplit,m,n,grid);

                result = min(result, top + bottomright + bottomleft);

                int topright = minArea(0,0,rowsplit,colsplit,grid);
                int topleft = minArea(0,colsplit,rowsplit,n,grid);
                int bottom = minArea(rowsplit,0,m,n,grid);

                result = min(result, bottom + topright + topleft);
            }
        }

        for(int rowsplit = 1; rowsplit < m; rowsplit++){
            for(int rowsplit_again = rowsplit+1; rowsplit_again < m; rowsplit_again++){

                int top = minArea(0,0,rowsplit,n,grid);
                int middle = minArea(rowsplit,0,rowsplit_again,n,grid);
                int bottom = minArea(rowsplit_again,0,m,n,grid);

                result = min(result, top + middle + bottom );
            }
        }

        return result;
    }

    vector<vector<int>> rotategrid(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rotatedGrid(n, vector<int>(m,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rotatedGrid[j][m-i-1] = grid[i][j];
            }
        }
        return rotatedGrid;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int result = util(grid);
        vector<vector<int>> rotatedgrid = rotategrid(grid);
        result = min(result, util(rotatedgrid));
        return result;
    }
};