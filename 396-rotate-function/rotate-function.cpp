class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        int first = 0;
        for(int i = 0; i < nums.size(); i++){
            first = first + i * nums[i];
        }
        int maxf = first;
        int curr = 0;
        int prev = first;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            curr = prev + sum - (n)*nums[n-i];
            maxf = max(maxf, curr);
            prev = curr;
        }

        // cout << "first: " << first << endl;
        return maxf;
    }
};