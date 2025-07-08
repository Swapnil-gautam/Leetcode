// class Solution {
// public:

//     int rec(vector<vector<int>>& events, int i, int k, int prevend, vector<vector<vector<int>>> dp){
//         if(k <= 0 || i >= events.size()){ 
//             return 0;
//         }
        
//         // cout << "i: " << i << " k: " << k << " prevend: "<< prevend << endl;
//         // cout << dp[i][k][prevend] << endl;
//         if(dp[i][k][prevend] != -1){
//             return dp[i][k][prevend];
//         }

//         int take = 0;
//         if(prevend < events[i][0]){
//             take = events[i][2] + rec(events, i+1, k-1, events[i][1], dp);
//         }
        
//         int nottake = rec(events, i+1, k, prevend, dp);

//         return dp[i][k][prevend] = max(take, nottake);

//     }
//     int maxValue(vector<vector<int>>& events, int k) {
//         // sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
//         // return a[2] > b[2]; // Sort in ascending order of the third element
//         // });

//         // for(int i = 0; i < events.size(); i++){
//         //     cout << events[i][0] << events[i][1] << events[i][2] << endl;
//         // }

//         // int totalVal = 0;
        
//         // int currval = events[0][2];

//         // priority_queue <int , vector<int>, greater<int>> pq;

//         // while(k > 0){
//         //     while(i < events.size()){
//         //         if(currval == events[i][2]){
//         //             pq.push()
//         //         }

//         //     }
            
//         // }


//         sort(events.begin(), events.end());

//         int t = 0;
//         for(int i = 0; i < events.size(); i++){
//             t = max(t, events[i][1]);
//         }

//         int n = events.size();
//         int m = k;
        
//         // cout << "n: " << n << " m: " << m << " t: " << t << endl;
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(t+1, -1)));

//         return rec(events, 0, k, 0, dp);
//     }
// };



class Solution {
public:
    vector<vector<int>> dp;
    int n;
    vector<int> next;

    int attend(int i, int num, vector<vector<int>>& events){
        if (i == n || num == 0) return 0;
        if (dp[i][num] != -1) return dp[i][num];

        // Attend the event i
        int attend_i = events[i][2] + attend(next[i], num - 1, events);

        // Skip the event i
        int skip_i = attend(i+1, num, events);

        // Choose the maximum of attend_i& skip_i
        int ans = max(attend_i, skip_i);
        return dp[i][num] = ans;
    }
    int maxValue(vector<vector<int>>& events, int num) {
        n = events.size();
        sort(events.begin(), events.end());
        dp.assign(n + 1, vector<int>(num + 1, -1));
        next.assign(n, n);
        for(int i=0; i<n; i++){
            next[i]=upper_bound(events.begin()+i, events.end(), vector<int>{events[i][1]+1,0,0})-events.begin();
        }
        return attend(0, num, events);
    }
};