// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n = intervals.size();

//         vector<vector<int>> res;
//         int mergei = 0;
//         int mergej = 0;

//         if(n == 0){
//             res.push_back(newInterval);
//             return res;
//         }

//         int j = 0;
//         for(int i = 0; i<n; i++){
//             if(intervals[i][1] >= newInterval[0]){
//                 // mergei = intervals[i][0];
//                 // if(intervals[i][0] > newInterval[0]){
//                 //     mergei = newInterval[0];
//                 // }else{
//                 //     mergei = intervals[i][0];
//                 // }
//                 mergei = min(newInterval[0], intervals[i][0]);
//                 j = i;
//                 break;
//             }
//             res.push_back(intervals[i]);
//         }

//         for(int i = j; i<n; i++){
//             if(intervals[i][1] >= newInterval[1]){
//                 // mergei = intervals[i][0];
//                 if(intervals[i][0] > newInterval[1]){
//                     mergej = newInterval[1]; 
//                     j = i;
//                 }else{
//                     mergej = intervals[i][1];
//                     j = i+1;
//                 }
//                 break;
//             }else{
//                 mergej = max(intervals[i][1], newInterval[1]);
//             }
//         }

//         res.push_back({mergei, mergej});

//         for(int i = j; i<n; i++){
//             res.push_back(intervals[i]);
//         }

//         //cout << "mergei: " << mergei << " mergej: " << mergej << " j: " << j << endl; 

//         return res;

//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};