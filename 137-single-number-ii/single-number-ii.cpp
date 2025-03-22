class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int checkbit = 1;
        int res = 0;
        for(int i = 0; i < 32; i++){
            ones = 0;
            // cout << checkbit << endl;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & checkbit){
                    ones++;
                }
            }

            if(ones%3!=0){
                res = res | checkbit;
            }

            checkbit = checkbit << 1;
        }

        return res;
    }
};