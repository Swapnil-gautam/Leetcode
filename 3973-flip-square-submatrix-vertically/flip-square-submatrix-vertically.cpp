class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(i == x && j == y){
                    // i = 1    j = 0
                    // cout << "i: " << i << " j: " << j << endl;
                    
                    // // for(int p = i; p<(x+k)/2; p++){
                    //     for(int q = j; q<j+k; q++){
                    //         cout << "p: " << p << " q: " << q << endl;
                    //         int temp = grid[p+k-1][q];
                    //         grid[p+k-1][q] =  grid[p][q];
                    //         grid[p][q] = temp;
                    //     }
                    // }
                    for(int p = i; p < i + k/2; p++){
                        for(int q = j; q < j + k; q++){
                            int temp = grid[p][q];
                            grid[p][q] = grid[i + k - 1 - (p - i)][q];
                            grid[i + k - 1 - (p - i)][q] = temp;
                        }
                    }
                }
            }
        }

        return grid;
    }
};