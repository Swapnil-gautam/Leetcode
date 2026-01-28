// class Solution {
// public:
//     int traverse(vector<vector<int>>& grid, int i, int j){
//         if(i == 0 && j == 0){
//             return grid[i][j];
//         }

//         int moveup = INT_MAX;
//         int moveleft = INT_MAX;

//         if(j - 1 >= 0){
//             moveup = grid[i][j] + traverse(grid, i, j-1);
//         }
//         if(i - 1 >= 0){
//             moveleft = grid[i][j] + traverse(grid, i-1, j);
//         }
        
//         return min(moveup, moveleft);

//     }

//     int minCost(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> memo(m, vector<int>(n, -1));

//         int res = traverse(grid, m-1, n-1);
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 cout << grid[i][j] << " ";
//             }

//             cout << endl;
//         }

//         return res;
//     }
// };


class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
             [&](const auto& p1, const auto& p2) -> bool {
                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
             });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost =
                    min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] ==
                        grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] =
                            min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] =
                            min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};