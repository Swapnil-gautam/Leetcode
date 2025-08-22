class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = -1;
        int maxY = -1;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(minX > i){
                        minX = i;
                    }
                    if(minY > j){
                        minY = j;
                    }
                    if(maxX < i){
                        maxX = i;
                    }
                    if(maxY < j){
                        maxY = j;
                    }
                }
            }
        }

        cout << "minX: " <<  minX << endl;
        cout << "minY: " <<  minY << endl;
        cout << "maxX: " <<  maxX << endl;
        cout << "maxY: " <<  maxY << endl;

        return (((maxX - minX)+1) * ((maxY - minY)+1));

    }
};