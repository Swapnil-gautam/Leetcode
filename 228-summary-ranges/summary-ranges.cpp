// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         int n = nums.size();
//         vector<string> res;
//         string s;

//         int i = 0;
//         int j = 1;

//         while(j <= n){
//             // cout << "i: " << i << " : " << nums[i] << " j: " << j << " : " << nums[j] << endl;
//             if(j == n || nums[j]-nums[j-1] != 1){
//                 if(j-i == 1){
//                     s = to_string(nums[i]);
//                     res.push_back(s);
//                 }else{
//                     s = to_string(nums[i]) + "->" + to_string(nums[j-1]);
//                     res.push_back(s);
//                 }
//                 i = j;
//             }
//             j++;
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> arr;
        int curr = 0; 
        int n = nums.size(); 
        
        for (int i = 1; i <= n; i++) { 
            
            if (i == n || nums[i - 1] + 1 != nums[i]) {
                if (curr == i - 1) { 
                   
                    arr.push_back(to_string(nums[curr]));
                } else {
                    
                    arr.push_back(to_string(nums[curr]) + "->" + to_string(nums[i - 1]));
                }
                curr = i; 
            }
        }
        return arr;
    }
};
