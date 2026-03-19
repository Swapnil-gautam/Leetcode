// class Solution {
// public:
//     int numberOfSubmatrices(vector<vector<char>>& grid) {
//         int count = 0; 
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> intgrid(m, vector<int>(n, 0));

//         bool oneX = false;

//         if(grid[0][0] == 'X'){
//             intgrid[0][0] = 1;
//             oneX = true;
//         }else if(grid[0][0] == 'Y'){
//             intgrid[0][0] = -1;
//         }

//         for(int i = 1; i < m; i++){
//             if(grid[i][0] == 'X'){
//                 intgrid[i][0] = 1 + intgrid[i-1][0];
//                 oneX = true;
//             }else if(grid[i][0] == 'Y'){
//                 intgrid[i][0] = -1 + intgrid[i-1][0];
//             }else{
//                 intgrid[i][0] = intgrid[i-1][0];
//             }
//             if(intgrid[i][0] == 0 && oneX == true){
//                 count++;
//             }
//         }

//         for(int i = 1; i < n; i++){
//             if(grid[0][i] == 'X'){
//                 intgrid[0][i] = 1 + intgrid[0][i-1];
//                 oneX = true;
//             }else if(grid[0][i] == 'Y'){
//                 intgrid[0][i] = -1 + intgrid[0][i-1];
//             }else{
//                 intgrid[0][i] = intgrid[0][i-1];
//             }
//             if(intgrid[0][i] == 0 && oneX == true){
//                 count++;
//             }
//         }

//         for(int i = 1; i < m; i++){
//             for(int j = 1; j < n; j++){
//                 if(grid[i][j] == 'X'){
//                     intgrid[i][j] = 1 + intgrid[i-1][j] + (intgrid[i][j-1] - intgrid[i-1][j-1]);
//                     oneX = true;
//                 }else if(grid[i][j] == 'Y'){
//                     intgrid[i][j] = -1 + intgrid[i-1][j] + (intgrid[i][j-1] - intgrid[i-1][j-1]);
//                 }else{
//                     intgrid[i][j] = intgrid[i-1][j] + (intgrid[i][j-1] - intgrid[i-1][j-1]);
//                 }

//                 if(intgrid[i][j] == 0 && oneX == true){
//                     count++;
//                 }
//             }
//         }

//         // for(int i = 0; i < m; i++){
//         //     for(int j = 0; j < n; j++){
//         //         cout <<  intgrid[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }

//         return count;
//     }
// };


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                if(j-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }
                
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
                

            }
        }

        return count;
    }
};