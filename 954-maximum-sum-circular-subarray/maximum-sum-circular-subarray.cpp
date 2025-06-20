class Solution {
public:

    int kadanesMax(vector<int>& nums, int n){
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i<n; i++){
            sum = max(sum + nums[i],nums[i]); // agar aapne usko current value se chota hi kardiya toh usko current value ke equale hi kardo 
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

    int kadanesMin(vector<int>& nums, int n){
        int sum = nums[0];
        int minSum = nums[0];

        for(int i = 1; i<n; i++){
            sum = min(sum + nums[i],nums[i]); // agar aapne usko current value se bada hi kardiya toh usko current value ke equale hi kardo 
            minSum = min(minSum, sum);
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        int TotalSum = accumulate(begin(nums), end(nums), 0);
        
        int maxSum = kadanesMax(nums, n);

        int minSum = kadanesMin(nums, n);

        int CircularMaxSum = TotalSum - minSum;

        // maxSum = max(maxSum, CircularMaxSum);

        if(maxSum > 0){
            return  max(maxSum, CircularMaxSum);
        }

        // cout << " minSum: " << minSum << endl;
        // cout << " maxSum: " << maxSum << endl;
        // cout << " TotalSum: " << TotalSum << endl;

        return maxSum;
    }
};