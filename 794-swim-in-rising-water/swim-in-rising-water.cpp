// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
        
//     }
// };


class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    using P = pair<int, pair<int, int>>; // {time, {i, j}}

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap by time
        result[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();

            // if we reached destination, return time
            if (i == n - 1 && j == n - 1)
                return currTime;

            // Skip if we’ve already found a better path
            if (currTime > result[i][j]) continue;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                    int nextTime = max(currTime, grid[i_][j_]);

                    if (nextTime < result[i_][j_]) {
                        result[i_][j_] = nextTime;
                        pq.push({nextTime, {i_, j_}});
                    }
                }
            }
        }

        return -1; // should never reach here
    }
};
