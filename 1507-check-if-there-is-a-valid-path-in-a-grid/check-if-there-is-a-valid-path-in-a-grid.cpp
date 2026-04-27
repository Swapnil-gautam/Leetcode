class Solution {
public:
    bool isvalid(int y, int x, vector<vector<int>>& grid){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()){
            return false;
        }
        return true;
    }

    int oppdirt(int dir){
        if(dir == 0){
            return 1;
        }else if(dir == 1){
            return 0;
        }else if(dir == 2){
            return 3;
        }else if(dir == 3){
            return 2;
        }

        return -1;
    }

    bool checkpath(int dir, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& streets, vector<vector<int>>& visited){
        // cout << "init i: " << i << " init j: " << j << " dir: " << dir << endl;
        if( i == grid.size()-1 && j == grid[0].size()-1){
            // cout << "fi: " << i << " fj: " << j << endl;
            return true;
        }

        if(visited[i][j] != 0 && i != 0 && j != 0){
            return false;
        }
        visited[i][j] = 1;

        int ni = i; 
        int nj = j;

        if(dir == 0){
            nj--;
        }else if(dir == 1){
            nj++;
        }else if(dir == 2){
            ni--;
        }else if(dir == 3){
            ni++;
        }

        if(!isvalid(ni, nj, grid)){
            return false;
        }

        int oppd = oppdirt(dir);
        // cout << "i: " << i << " j: " << j << " ni: " << ni << " nj: " << nj << endl;
        vector<int> nextstreet = streets[grid[ni][nj]-1];
        
        if(nextstreet[oppd] != 1){
            return false;
        }

        // cout << "dir: " << dir << " oppd: " << oppd << " nextstreet[oppd]: " << nextstreet[oppd] << endl;

        for( int k = 0; k < 4; k++){
            // cout << nextstreet[k] << " ";
            if(k != oppd && nextstreet[k] != 0){
                dir = k;
            }
        }
        // cout << endl;

        return (checkpath(dir, ni, nj, grid, streets, visited));

    }

    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> streets = 
            {{1,1,0,0}, 
             {0,0,1,1}, 
             {1,0,0,1}, 
             {0,1,0,1}, 
             {1,0,1,0}, 
             {0,1,1,0}
            };

        vector<vector<int>> visited (grid.size()+1, vector<int>(grid[0].size()+1, 0));

        vector<int> fstreet = streets[grid[0][0]-1];
        for(int i = 0; i < fstreet.size(); i++){
            if(fstreet[i] == 0){
                continue;
            }
            if(checkpath(i, 0, 0, grid, streets, visited)){
                return true;
            }
        }

        return false;
    }
};