// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         queue<pair<int,int>> qu;
//         int r = grid.size();
//         int c = grid[0].size();

//         int island = 0;
//         qu.push(pair(0,0));

//         while(!qu.empty()){
//             int size = qu.size();
//             // cout << size << endl;
//             int check = 0; 
//             while(size > 0){
//                 pair<int,int> curr = qu.front();
//                 qu.pop();
//                 int i = curr.first;
//                 int j = curr.second;
//                 int  val = grid[i][j] - '0';
//                 check = check + val;
//                 if(i+1<r){
//                     qu.push(pair(i+1,j));
//                 }
//                 if(j+1<c){
//                     //cout << qu.front().first << " " << qu.front().second << " : " << " i: " << i << " j: " << j << endl;
//                     if(qu.front().first != i && qu.front().second != j+1){
//                         qu.push(pair(i,j+1));
//                     }
//                 }
//                 //cout << "i: " << i << " j: " << j << " val: " << val << " r: " << r << " c: " << c << endl;
//                 size--;
//             }
//             if(check > 0){
//                 cout << " island" << endl;
//             }else{
//                 cout << "not island" << endl;
//             }
            
//         }


//         return island;
//     }
// };


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') {
                            continue;
                        }
                        
                        grid[x][y] = '0'; // mark as visited
                        
                        for (auto& dir : directions) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};