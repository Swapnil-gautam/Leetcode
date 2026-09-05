class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int>maxvec(n, 0);
        vector<int>minvec(n, 0);

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            maxvec[i] = maxi;
            mini = min(mini, nums[n-i-1]);
            minvec[n-i-1] = mini;
        }

        int minscore = INT_MAX;
        int minscorei = -1;
        int score = 0;
        for(int i = 0; i < n; i++){
            score = maxvec[i] - minvec[i];
            if(score <= k){
                minscore = min(minscore, score);
                minscorei = i;
                return minscorei;
            }
        }

        return minscorei;
    }
};