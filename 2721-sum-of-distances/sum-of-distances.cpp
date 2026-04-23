// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         unordered_map<int, vector<int>> pos;
//         vector<long long> res;
//         for(int i = 0; i < nums.size(); i++){
//             pos[nums[i]].push_back(i);
//         }

//         for(int i = 0; i < nums.size(); i++){
//             long long sum = 0;
//             for(auto j : pos[nums[i]]){
//                 // cout << "i: " << i << " j: " << j << endl;
//                 sum = sum + abs(j - i);
//             }
//             res.push_back(sum);
//         }
//         return res;
//     }
// };


class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;   //nums[i] -> sum of i's
        unordered_map<int, ll> indexCount; //nums[i] -> frequency

        //Left to Right
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        indexSum.clear();
        indexCount.clear();

        //Right to Left
        for(int i = n-1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        return arr;
    }
};
