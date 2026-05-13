// class Solution {
// public:

//     int minMoves(vector<int>& nums, int limit) {
//         unordered_map<int, int>sumfreq;
//         int n = nums.size();
//         for(int i = 0; i < n/2; i++){
//             sumfreq[nums[i]+nums[n-1-i]]++;
//         }
//         int maxfreqsum = 0;
//         int maxfreq = 0;
//         for(auto frq: sumfreq){
//             if( frq.second > maxfreq){
//                 maxfreq = frq.second;
//                 maxfreqsum = frq.first;
//             }
//         }
//         int count = 0;
//         for(int i = 0; i < n/2; i++){
//             if( nums[i]+nums[n-1-i] != maxfreqsum){
//                 if(nums[i]+limit >= maxfreqsum || nums[n-1-i]+limit >= maxfreqsum){
//                     count = count + 1;
//                 }else if(limit + limit >= maxfreqsum){
//                     count = count + 2;
//                 }else{
//                     return -1;
//                 }
//             }
//         }
//         // cout << maxfreqsum << " : " << maxfreq << endl;
//         return count;
//     }
// };



class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            diff[2] += 2;
            diff[2*limit+1] -= 2;

            //for moves = 1
            diff[minVal]   += (-1);
            diff[maxVal+1] -= (-1);

            //for moves = 0 [a+b, a+b]
            diff[a+b]   += (-1);
            diff[a+b+1] -= (-1);
        }

        int result = INT_MAX;

        for(int sum = 2; sum <= 2*limit; sum++) {
            diff[sum] += diff[sum-1];

            result = min(result, diff[sum]);
        }

        return result;
    }
};
