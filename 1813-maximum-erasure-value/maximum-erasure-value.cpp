// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         unordered_map<int, int> uniq;
//         int sum = 0;

//         // for(int i = 0; i < nums.size(); i++){
//         //     if(uniq.find(nums[i]) == uniq.end()){
//         //         uniq.insert(nums[i]);
//         //         sum += nums[i];
//         //     }
//         // }

//         int i = 0;
//         int maxSum = 0;
//         int preffixsum = 0;
//         while(i < nums.size()){
//             preffixsum = preffixsum + nums[i]; 

//             if(uniq.find(nums[i]) == uniq.end()){
//                 sum = sum + nums[i] ;
//             }else{
//                 sum = preffixsum - uniq[nums[i]];
//             }
            
//             uniq[nums[i]] = preffixsum;
//             maxSum = max(sum , maxSum);
//             cout << "nums[i]: " << nums[i] << " i: " << i << " sum: " << sum << endl;
//             i++;
//         }

//         return maxSum;
//     }
// };



class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> cus(n, 0);
        cus[0] = nums[0];
        for(int i = 1; i < n; i++)
            cus[i] = cus[i-1] + nums[i];
        
        vector<int> mp(10001, -1); //Using as a map 1 <= nums[i] <= 10^4
        int maxS   = 0;
        int i      = 0;
        int j      = 0;
        
        while(j < n) {
            i       = max(i, mp[nums[j]]+1);
            int jthSum  = cus[j];
            int ithSum  = i-1 < 0 ? 0 : cus[i-1];
            maxS        = max(maxS, jthSum - ithSum);
            mp[nums[j]] = j;

            j++;
        }
        
        return maxS;
    }
};