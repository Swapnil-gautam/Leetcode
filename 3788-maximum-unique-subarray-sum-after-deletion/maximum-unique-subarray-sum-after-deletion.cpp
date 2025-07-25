class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        unordered_set<int> pos_uniq;
        int maxn = INT_MIN;
        for(int n: nums){
            if(n > 0){
                if(pos_uniq.find(n) == pos_uniq.end()){
                    pos_uniq.insert(n);
                }
            }

            maxn = max(maxn, n);
        }

        if(pos_uniq.empty()){
            return maxn;
        }

        int sum = 0;
        for(auto p: pos_uniq){
            sum = sum + p;
        }

        return sum;
    }
};