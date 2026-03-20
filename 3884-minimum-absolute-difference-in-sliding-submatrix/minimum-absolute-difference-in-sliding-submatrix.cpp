class Solution {
public:

    void setkgrid(vector<vector<int>>& grid, int k, int a, int b, set<int>& kgrid){
        if(!kgrid.empty()){
            kgrid.clear();
        }
        
        // cout << "grid.size(): " << grid.size() << endl;
        // cout << "grid[0].size(): " << grid[0].size() << endl;
        // cout << "a+k: " << a+k << "  b+k: " << b+k << endl;

        if(a+k <= grid.size() &&  b+k <= grid[0].size()){
            for(int i = a; i < a+k; i++){
                for(int j = b; j < b+k; j++){
                    // cout << grid[i][j]  << " ";
                    kgrid.insert(grid[i][j]);
                }
                // cout << endl;
            }
        }

        return;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        set<int> kgrid;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            vector<int> rowvec;
            for(int j = 0; j < n; j++){
                setkgrid(grid, k , i, j, kgrid);
                int minval = INT_MAX;
                // cout << "kgrid: " << kgrid.size() << endl;
                if(kgrid.empty()){
                    continue;
                }
                else if(kgrid.size() == 1){
                    rowvec.push_back(0);
                    kgrid.erase(*kgrid.rbegin());
                }else{
                    int prev = *kgrid.rbegin();
                    int curr = 0;
                    kgrid.erase(prev);
                    // cout << "prev: " << prev << endl;
                    while(!kgrid.empty()){
                        curr = *kgrid.rbegin();
                        // cout << "curr: " << curr << endl;
                        // cout << "abs(prev - curr): " << abs(prev - curr) << endl;
                        minval = min(minval, abs(prev - curr));
                        prev = curr;
                        kgrid.erase(prev);
                    }
                    rowvec.push_back(minval);
                }
            }
            if(rowvec.size() != 0){
                res.push_back(rowvec);
            }
            
        }

        return res;
    }
};