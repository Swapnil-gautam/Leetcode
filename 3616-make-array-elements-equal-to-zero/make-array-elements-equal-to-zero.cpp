// class Solution {
// public:
//     int countValidSelections(vector<int>& nums) {
        
//     }
// };


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalsum = 0;
        for(int i = 0; i < nums.size(); i++){   
            totalsum = totalsum + nums[i];
        }
        int prevSum = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 ){
                // cout << "totalsum/2: " << totalsum/2 << " prevSum: " << prevSum << endl;
                if(prevSum*2 == totalsum){
                    res = res + 2;
                }else if( abs((prevSum*2) - totalsum) == 1 ){
                    res = res + 1;
                }
                
            }
            prevSum = prevSum + nums[i];
        }
        return res;
    }
};