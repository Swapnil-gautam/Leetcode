class Solution {
public:
    // int solve(vector<vector<int>>& mat, int i, int j){
    //     if(i >= mat.size() || j >= mat[0].size()){
    //         return 0;
    //     }

    //     if(mat[i][j] == 0){
    //         return 0;
    //     }

    //     int right = 1 + solve(mat, i, j+1);

    //     cout << "i: " << i << " j: " << j << " right: " << right << endl;

    //     int down = 1 + solve(mat, i+1, j);

    //     cout << "i: " << i << " j: " << j << " left: " << left << endl;

    //     // return right + down;
    //     // return down;
    //     // return right;
    // }

    int consOnes(vector<int>& Onecolums){
        int cons = 0;
        int sum = 0;

        for(int i = 0; i < Onecolums.size(); i++){
            if(Onecolums[i]==0){
                cons = 0;
            }else{
                cons++;
            }

            sum += cons;
        }
        // sum += cons;

        return sum;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;

        for(int startrow = 0; startrow < m; startrow++){
            vector<int> Onecolums(n,1);
            for(int endrow = startrow; endrow < m; endrow++){
                for(int col = 0; col < n; col++){
                    Onecolums[col] = Onecolums[col] & mat[endrow][col];
                }
                res += consOnes(Onecolums);
                // cout << "res: " << res << endl;
            }
        }
        return res;
    }
};