// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();

//         vector<vector<char>> OcCheck(m ,vector<char>(n, 'O'));
//         vector<vector<int>> result;

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 // cout << "i: " << i << " j: " << j << " h: " << heights[i][j]  << endl;
//                 if(i == 0 || j == 0){
//                     OcCheck[i][j] = 'P';
//                 }else{
//                     if(heights[i-1][j] <= heights[i][j] && OcCheck[i-1][j] == 'P'){
//                         OcCheck[i][j] = 'P';
//                     }else if(heights[i][j-1] <= heights[i][j] && OcCheck[i][j-1] == 'P'){
//                         OcCheck[i][j] = 'P';
//                     }
//                 }
//             }
//         }

//         for(int i = m-1; i >= 0; i--){
//             for(int j = n-1; j >= 0; j--){
//                 // cout << "i: " << i << " j: " << j << " OC: " << OcCheck[i][j] << " "  << endl;
//                 if(i == m-1 || j == n-1){
//                     if(OcCheck[i][j] == 'P'){
//                         result.push_back({i,j});
//                         // cout << "i: " << i << " j: " << j << endl;
//                     }
//                     OcCheck[i][j] = 'A';
//                 }else{
//                     if(heights[i+1][j] <= heights[i][j] && OcCheck[i+1][j] == 'A'){
//                         if(OcCheck[i][j] == 'P'){
//                             result.push_back({i,j});
//                             // cout << "i: " << i << " j: " << j << endl;
//                         }
//                         OcCheck[i][j] = 'A';
//                     }else if(heights[i][j+1] <= heights[i][j] && OcCheck[i][j+1] == 'A'){
//                         if(OcCheck[i][j] == 'P'){
//                             result.push_back({i,j});
//                             // cout << "i: " << i << " j: " << j << endl;
//                         }
//                         OcCheck[i][j] = 'A';
//                     }
//                 }
//                 // cout << OcCheck[i][j] << " ";
//             }
//             // cout << endl;
//         }

//         return result;
//     }
// };



class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) { //invalid cell
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); //rows
        int n = heights[0].size(); //cols

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false)); //pacificVisited[i][j] = true, means [i][j] water can go to Pacific //m*n
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); //atlanticVisited[i][j] = true, means [i][j] water can go to atlantic //m*n
        //T.C : O(m*n)
        //S.C : O(m*n)


        //Top Row and Bottom Row
        //Top Row : Pacific connected already
        //Bottom Row : atlantic connected already

        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited); //Top Row
            DFS(heights, m-1, j, INT_MIN, atlanticVisited); //Top Row
        }

        //First col and last column
        //First col : Pacific connected already
        //Last col : atlantic connected already
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited); //First column
            DFS(heights, i, n-1, INT_MIN, atlanticVisited); //Last Column
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};