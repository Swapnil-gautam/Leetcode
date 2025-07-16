// class Solution {
// public:

//     int solve(vector<int>& nums, int i, int need){
//         if(i == nums.size()){
//             return 0;
//         }

//         int take = 0;
//         int notake = 0;

//         if(need == (nums[i]%2)){

//         }
//         take = 1 + solve(nums, i+1 );
//         notake = solve(nums, i+1 );

//         return max(take, notake);

//     }

//     int maximumLength(vector<int>& nums) {
//         int i = 0;
//         int need = 0;
//         return max(solve(nums, i, need), solve(nums, i, 1));
//     }
// };





class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0;
        for (int num : nums) {
            if (num % 2 == 0) countEven++;
            else countOdd++;
        }

        // Try building alternating parity subsequence
        int altLen = 1; // At least one number
        int prevParity = nums[0] % 2;

        for (int i = 1; i < nums.size(); ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prevParity) {
                altLen++;
                prevParity = currParity;
            }
        }

        return max({countEven, countOdd, altLen});
    }
};