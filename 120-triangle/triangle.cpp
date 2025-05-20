class Solution {
public:

    // int rec(vector<vector<int>>& triangle, int i, int j){
    //     if(i == triangle.size()-1){
    //         return triangle[i][j];
    //     }

    //     int d = triangle[i][j] + rec(triangle, i+1,j);
    //     int dg = triangle[i][j] + rec(triangle, i+1,j+1);

    //     return min(d, dg);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0), curr(n,0);
        for(int i = 0; i<triangle[n-1].size(); i++){
            front[i] = triangle[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                // cout << front[j] << endl;
                // cout << front[j+1] << endl;
                // cout << triangle[i][j] << endl;
                // cout << "**************" << endl;

                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                curr[j]  = min(d, dg);
            }
            front = curr;
        }

        return front[0];


        // return rec(triangle, 0, 0);
                
    }
};




        // wrong interpretion of the problem
        // int sum = 0;
        // for(int i = 0; i < triangle.size(); i++){
        //     int min = triangle[i][0];
        //     for(int j = 0; j < triangle[i].size(); j++){
        //         if(min > triangle[i][j]){
        //             min = triangle[i][j];
        //         }
        //     }
        //     sum = sum + min;
        // }
        // return sum;
