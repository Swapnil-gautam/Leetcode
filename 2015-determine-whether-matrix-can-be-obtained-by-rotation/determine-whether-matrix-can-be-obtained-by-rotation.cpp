class Solution {
public:

    void flipH(vector<vector<int>>& mat){
        for(int i = 0; i < mat.size()/2; i++){
            for(int j = 0; j < mat.size(); j++){
                swap(mat[i][j], mat[mat.size()-1 - i][j]);
            }
        }
    }

    void flipD(vector<vector<int>>& mat){
        for(int i = 0; i < mat.size(); i++){
            for(int j = i; j < mat.size(); j++){
                if(i != j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target){
         return true;
        }

        for(int i = 0; i < 3; i++){
            flipH(mat);
            flipD(mat);
            if(mat == target){
                return true;
            }
        }

        return false;
    }
};