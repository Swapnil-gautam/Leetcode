class Solution {
public:
    pair<int, int> PosToRC(int pos, int n){
        int r = n - ((pos-1)/n) - 1;
        int c = (pos-1)%n;
        if(r%2 == n%2){
            c = (n - (pos-1)%n)-1;
        }
        return pair(r,c);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        queue<int> qu;
        int pos = 1;
        qu.push(pos);
        vector<int> visited(n*n+1, 0);
        visited[0] = 1;
        int move = 0;
        while(!qu.empty()){
            int size = qu.size();
            for(int  j = 0; j < size; j++){
                pos = qu.front();
                //cout << "pos: " << pos << endl;
                if(pos == n*n){
                    return move;
                }
                qu.pop();
                for(int i = 1; i <= 6; i++){
                    if(pos+i <= n*n && visited[pos+i] == 0){
                        int curr = pos+i;
                        auto t = PosToRC(curr,n);
                        //cout << "curr: " << curr << " r: " << t.first << " c: "<< t.second << " : " << board[t.first][t.second] << endl; 
                        //cout << "curr: " << curr << " : " << board[t.first][t.second] << endl; 
                        visited[curr] = 1;
                        if(board[t.first][t.second] != -1){
                            curr = board[t.first][t.second];
                        }
                        //cout << "pos+i: " << pos+i << endl;
                        // visited[curr] = 1;
                        qu.push(curr);
                    }
                }
            }
            move = move + 1;
            //cout << "**************" << endl;
        }
        return -1;
    }
};