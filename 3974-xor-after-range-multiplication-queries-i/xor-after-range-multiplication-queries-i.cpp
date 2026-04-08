class Solution {
public:
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for(int j = l; j <= r; j = j + k){
                // nums[j] = nums[j] % MOD;
                // v = v % MOD;
                nums[j] = (1LL * nums[j] * v) % MOD;
            }
        }
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};