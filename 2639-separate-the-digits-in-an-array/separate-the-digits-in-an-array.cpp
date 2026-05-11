class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int i = nums.size()-1; i >= 0; i--){
            int t = nums[i];
            int r = 0;
            if( t == 0){
                // res.push_back(r);
                res.insert(res.begin(), r); 
            }
            while(t > 0){
                r = t%10;
                t = t/10;
                // res.push_back(r);
                res.insert(res.begin(), r); 
            }
        }
        return res;
    }
};