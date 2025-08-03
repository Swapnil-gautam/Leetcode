// class Solution {
// public:
//     int solve(unordered_map<int, int>& PosPoint, int currPos, int k, int l, int r){
//         if(k == 0){
//             if(PosPoint.find(currPos) != PosPoint.end()){
//                 return PosPoint[currPos];
//             }else{
//                 return 0;
//             }

//             // return 0;
//         }

//         int left = 0;
//         int right = 0;
//         // cout <<"currPos: " << currPos <<" k: " << k << " l: " << l << " r:" << r << endl;
//         if(PosPoint.find(currPos) != PosPoint.end()){
//             auto temp = PosPoint; 
//             temp[currPos] = 0;
//             left = PosPoint[currPos] + solve(temp, currPos-1, k-1, l+1, r);
//             // cout <<"left1:" << left << endl;
//             right = PosPoint[currPos] + solve(temp, currPos+1, k-1, l, r+1);
//             // cout <<"right1:" << right << endl;
//         }else{
//             left = solve(PosPoint, currPos-1, k-1, l+1, r);
//             right = solve(PosPoint, currPos+1, k-1, l, r+1);
//             // cout <<"left2:" << left << endl;
//             // cout <<"right2:" << right << endl;
//         }

//         return max(left, right);
//     }
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

//         unordered_map<int, int> PosPoint;

//         for(int i = 0; i < fruits.size(); i++){
//             PosPoint[fruits[i][0]] = fruits[i][1];
//         } 

//         return solve(PosPoint, startPos, k, 0, 0);
//     }
// };




class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> indices(n);

        // Build prefix sum and extract indices
        for (int i = 0; i < n; i++) {
            indices[i]   = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFrutis = 0;

        for (int d = 0; d <= k / 2; d++) {
            // Move
            int remain = k - 2 * d;
            int i   = startPos - d;
            int j  = startPos + remain;

            int left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }

            // Second case: move right x, then left (k - 2x)
            i  = startPos - remain;
            j  = startPos + d;
            
            left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }
        }

        return maxFrutis;
    }
};