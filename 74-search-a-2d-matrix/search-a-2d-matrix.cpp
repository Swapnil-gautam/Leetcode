class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // int i = 0;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        int low = 0;
        int high = m;
        int mid;
        int curr = matrix[low][0];
        while(low <= high){
            mid = (low + high)/2;
            if(target == matrix[mid][0] || target == matrix[mid][n]){
                return true;
            }
            if(target > matrix[mid][0] && target < matrix[mid][n]){
                int nlow = 0;
                int nhigh  = n;
                int nmid;

                // cout << matrix[mid][0] << " " << matrix[mid][n] << " " <<  mid << endl;
                // return true;

                while(nlow <= nhigh){

                    nmid = (nlow + nhigh)/2;
                    //cout << matrix[mid][nmid] << " " <<  mid << " " << nmid << " " << nlow << " " << nhigh << endl;
                    if(target == matrix[mid][nmid]){
                        return true;
                    }

                    if(target < matrix[mid][nmid]){
                        nhigh = nmid-1;
                    }else{
                        nlow = nmid+1;
                        //cout << "low updated: " << low << endl;
                    }
                    //cout << matrix[mid][nmid] << " " <<  mid << " " << nmid << " " << nlow << " " << nhigh << endl;
                }

                return false;
                
            }else if(target < matrix[mid][0]){
                high = mid-1;
            }else if(target > matrix[mid][n]){
                low = mid+1;
            }
        }                

        return false;                           
    }    
};