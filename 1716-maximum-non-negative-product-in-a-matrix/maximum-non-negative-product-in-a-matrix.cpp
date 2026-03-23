// class Solution {
// public:
//     pair<int, int> solve(vector<vector<int>>& grid, int i, int j){
//         if(i == grid.size() || j == grid[0].size()){
//             return 1;
//         }

//         int down = 1;
//         int right = 1;
//         down = grid[i][j]*solve(grid, i+1, j);
//         right = grid[i][j]*solve(grid, i, j+1);

//         if(i == 0 &&  j == 0){
//             cout << "down: " << down << endl;
//             cout << "right: " << right << endl;
//         }

//         return ;
//     }
//     int maxProductPath(vector<vector<int>>& grid) {
//         return solve(grid, 0, 0);
//     }
// };


class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9+7;

    vector<vector<pair<ll, ll>>> t;
    
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        //Down
        if(i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }


        //Right
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};