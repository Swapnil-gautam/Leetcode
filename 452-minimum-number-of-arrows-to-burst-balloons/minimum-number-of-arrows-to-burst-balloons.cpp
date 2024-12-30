// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         int i = 0;
//         int j = 0;
//         int count = 0;
//         int n = points.size();
//         sort(points.begin(), points.end());

//         // for(int k = 0; k < n; k++){
//         //     cout << points[k][0] << " " << points[k][1]<< endl;
//         // }
//         cout << "j: "<< j << " n: "<< n << endl;
//         while(j<n){
//             if(points[j][0] <= points[i][1]){
//                 if(points[j][1] > points[i][1]){
//                     count++;
//                 }
//             }
//             else{
//                 if((j-i)==1){
//                     count++;
//                 }
//                 i = j;

//             }
//             j++;
//         }
        
//         cout << "i: "<< i << " j: "<< j << endl;

//         if((j-i)==1){
//             count++;
//         }

//         return count;
//     }
// };




class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        // for(int i = 0; i < points.size(); i++){
        //     cout << points[i][0] << " : "<< points[i][1] << endl;
        // }

        int count = 1;
        int high = points[0][1];

        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > high){
                high  = points[i][1];
                count++;
            }
        }
        return count;
    }

    // int findMinArrowShots(vector<vector<int>>& points) {

    //     sort(points.begin(), points.end());
    //     int n = points.size();
    //     int count = 1;

    //     int e = points[0][1];
    //     for(int i = 1; i < n; i++){
    //         if(points[i][0]>e){
    //             count++;
    //             e = points[i][1];
    //         }
    //     }

    //     return count;
    // }

};