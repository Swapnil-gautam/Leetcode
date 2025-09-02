// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points) {
//         sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
//             return a[1] > b[1]; // Compare the second elements
//         });

//         // set<vector<int>> checkset;
//         set<pair<int, int>> checkset;
//         for(int i = 0; i < points.size(); i++){
//             checkset.insert({points[i][0], points[i][1]});
//             cout << "i 0: " << points[i][0] << " 1: " << points[i][1] << endl;

//         }


//         int count = 0;
//         for(int i = 0; i < points.size(); i++){
//             for(int j = i+1; j < points.size(); j++){
//                 cout << "i: " << i << " j: " << j << endl;
//                 cout << "points[j][0]: "<< points[j][0] << " points[i][0]: "<< points[i][0] << endl;
//                 if(points[j][0] == points[i][0] || points[j][1] == points[i][1]){
//                     count++;
//                     break;
//                 }

//                 if(points[j][0] >= points[i][0]){
//                     cout << "Check 1: " << j << endl;
//                     if(checkset.find({points[i][0], points[j][1]}) == checkset.end()){
//                         cout << "hope hai " << endl;
//                         count++;
//                         break;
//                     }

//                 }
//             }
//         }

//         return count;
//     }
// };





//Approach-2 (Using Sorting)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // upper left

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];   // lower right

                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1) { //not lower right
                    continue;
                }

                if (y2 > bestY) {
                    result++;
                    bestY = y2;
                }
            }
        }

        return result;
    }
};