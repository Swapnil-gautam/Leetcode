// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         vector<int> res(n,0);
//         vector<int> occupied(n,0);

//         // int maxTime = 0;
//         // for(int i = 0; i < meetings.size(); i++ ){
//         //     if(maxTime < meetings[i][1]){
//         //         maxTime = meetings[i][1];
//         //     }
//         // }

//         // cout << maxTime << endl;

//         int minoccupied = INT_MAX;
//         int minoccupied_j = 0;
//         bool zerowasthere = false;

//         for(int i = 0; i < meetings.size(); i++ ){
//             zerowasthere = false;
//             minoccupied = occupied[0];
//             // cout <<  "0 ";
//             for(int t = 0; t < occupied.size(); t++){
//                 cout << occupied[t] << " " ;
//             } 
//             cout << endl;
//             for(int j = 0; j < occupied.size(); j++ ){
//                 if(occupied[j] != 0){
//                     occupied[j] = occupied[j] - meetings[i][0];
//                     if(occupied[j] < 0){
//                         occupied[j]  = 0;
//                     }
//                 }
//             }

//             for(int j = 0; j < occupied.size(); j++ ){
//                 if(occupied[j] == 0){
//                     occupied[j] = meetings[i][1] - meetings[i][0];
//                     res[j] = res[j] + 1;
//                     zerowasthere = true;
//                     break;
//                 }

//                 if(occupied[j] < minoccupied){
//                     minoccupied = occupied[j];
//                     minoccupied_j = j;
//                 }

//                 // cout <<  "1 ";
//                 // for(int t = 0; t < occupied.size(); t++){
//                 //     cout << occupied[t] << " " ;
//                 // } 

//                 // cout << endl;

//                 //cout << "minoccupied_j: " << minoccupied_j << "   minoccupied: " << minoccupied << endl;
//             }
            
//             if(!zerowasthere){
//                 occupied[minoccupied_j] = occupied[minoccupied_j] + (meetings[i][1] - meetings[i][0]);
//                 res[minoccupied_j] = res[minoccupied_j] + 1;
//             }

//             // cout << "2 ";
//             // for(int t = 0; t < occupied.size(); t++){
//             //     cout << occupied[t] << " " ;
//             // } 

//             // cout << endl;
//         }

//         int resmax = 0;
//         int r = 0;
//         for(int i = 0; i < res.size(); i++ ){
//             // cout << res[i] << endl;
//             if(resmax < res[i]){
//                 resmax = res[i];
//                 r = i;
//             }
//         }

//         return r;

        
//     }
// };



class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings)); //sort by starting time of meetings

        vector<int> roomsUsedCount(n, 0); //Each room is used 0 times in the beginning

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        //To store {earliest room empty time, room No.}
        
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        //To store rooms that are used
        for(int room = 0; room < n; room++) {
            unusedRooms.push(room); //All rooms are unused in the beginning
        }

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];

            //First see, by this time, which rooms can be empty now
            //And move them to unusedRooms
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else { //We don't have any room available now. Pick earliest end room
                int room          = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end-start), room});
                roomsUsedCount[room]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};