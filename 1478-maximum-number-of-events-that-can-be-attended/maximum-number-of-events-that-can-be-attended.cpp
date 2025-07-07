class Solution {
public:
    // int maxEvents(vector<vector<int>>& events) {
    //     sort(events.begin(), events.end());
    //     unordered_map<int, int> vis;
    //     int count = 0;

    //     for(int i = 0; i<events.size(); i++){
    //         cout << events[i][0] << " " << events[i][1] << endl;
    //         int curr = events[i][0];
    //         int end = events[i][1];
    //         while(curr <= end){
    //             if(vis.find(curr) == vis.end()){
    //                 cout << curr << endl;
    //                 vis[curr] = 1;
    //                 count++;
    //                 break;
    //             }
    //             curr++;
    //         }
    //     }

    //     return count;
    // }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int count = 0;
        int i = 0;
        int n = events.size();
        int day = events[0][0];

        priority_queue <int , vector<int>, greater<int>> pq;

        while(!pq.empty() || i < n ){
            if(pq.empty()){
                day = events[i][0];
            }
            //cout << "################" << endl;
            while( i < n && events[i][0] == day){
                cout << events[i][0] << " "<< events[i][1] << endl;
                pq.push(events[i][1]);
                i++;
                
            }

            //cout << "**************" << endl;
            if(!pq.empty()){
                pq.pop();
                count++;
            }
            day++;
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return count;
    }
};