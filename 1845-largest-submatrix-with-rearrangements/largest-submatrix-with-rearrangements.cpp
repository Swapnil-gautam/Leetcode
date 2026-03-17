class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>prevOnes(n,0);
        vector<int>currOnes(n,0);

        int area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    currOnes[j] = matrix[i][j];
                }else{
                    if(matrix[i][j] == 1){
                        currOnes[j] = prevOnes[j] + 1;
                    }else{
                        currOnes[j] = 0;
                    }
                }
            }
            prevOnes = currOnes;
            // for(int t = 0; t < n; t++){
            //     cout << prevOnes[t] << " "; 
            // }
            // cout << endl;
            sort(currOnes.begin(), currOnes.end(), greater<int>());
            
            for(int t = 0; t < currOnes.size(); t++){
                area = max(area, currOnes[t]*(t+1));
                // cout << "area: " << area << " currOnes[t]: " << currOnes[t] << endl;
            }
        }

        return area;
    }
};