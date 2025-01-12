    // solved 53 test case with this 
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int r = board.size();
//         int c = board[0].size();

//         queue<pair<int,int>> qu;
//         vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
//         vector<pair<int,int>> v;
//         bool change = false;
//         for(int i = 1; i < r-1; i++){
//             for(int j = 1; j < c-1; j++){
//                 if(board[i][j] == 'O'){
//                     //cout << i << " " << j << endl;
//                     qu.push(pair(i,j));
//                     change = true;
//                     while(!qu.empty()){
//                         int curr_i = qu.front().first;
//                         int curr_j = qu.front().second;
//                         board[curr_i][curr_j] = 'X';
//                         v.push_back(pair(curr_i, curr_j));
//                         if(curr_i == 0 || curr_i == r-1 || curr_j == 0 || curr_j == c-1){
//                             change = false;
//                         }
//                         cout << curr_i << " " << curr_j << " qu" <<  endl;
//                         qu.pop();
//                         for(auto& d: dir){
//                             int new_i = curr_i + d.first;
//                             int new_j = curr_j + d.second;
//                             if(new_i>=0 && new_j >=0 && new_i<r && new_j<c && board[new_i][new_j] == 'O'){
//                                 qu.push(pair(new_i,new_j));
//                             }
//                         }
//                     }

//                     if(change){
//                         // for(auto& vp: v){
//                         //     board[vp.first][vp.second] = 'X';
//                         // }
//                         v.clear();
//                     }else{
//                         for(auto& vp: v){
//                             board[vp.first][vp.second] = 'O';
//                         }
//                         v.clear();
//                     }

//                 } 
//             }
//         }
//     }
// };



//Before you go through the code, just read the intuition and 
//approach for better clarity
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O')
                {
                    vis[i][j]=1;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            vis[row][col]=1;
            q.pop();
            int dirx[]={-1, 0, 1, 0};
            int diry[]={0, 1, 0, -1};
            for(int i=0;i<4;i++)
            {
                int newr=row+dirx[i];
                int newc=col+diry[i];
                if(newr>=0 && newc>=0 && newr<m && newc<n && !vis[newr][newc] && board[newr][newc]=='O')
                q.push({newr, newc});
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }        
    }
};


