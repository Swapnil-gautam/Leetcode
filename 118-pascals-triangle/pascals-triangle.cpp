class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>temp(1,1);
        vector<vector<int>>res;

        // res.push_back(temp);


        for(int i = 0; i < numRows; i++){
            vector<int> newtemp(i+1, 1);
            // for(int j = 1; j < i+1; j++){
            //     newtemp[j] = res[i-1][j] + res[i-1][j-1];
            // }
            res.push_back(newtemp);
        }

        if(numRows == 1 || numRows == 2 ){
            return res;
        }

        for(int i = 2; i < numRows; i++){
            for(int j = 1; j < i; j++){
                // cout << "res[i-1][j]: " <<  res[i-1][j] << endl;
                // cout << "res[i-1][j]: " <<  res[i-1][j] << endl;
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }

        return res;
    }
};