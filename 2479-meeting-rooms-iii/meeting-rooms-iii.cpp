class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> res(n,0);
        vector<long long> occupied(n,0);

        // int maxTime = 0;
        // for(int i = 0; i < meetings.size(); i++ ){
        //     if(maxTime < meetings[i][1]){
        //         maxTime = meetings[i][1];
        //     }
        // }

        // cout << maxTime << endl;

        long long minoccupied = LLONG_MAX;
        int minoccupied_j = 0;
        bool zerowasthere = false;

        for(int i = 0; i < meetings.size(); i++ ){
            zerowasthere = false;
            minoccupied = occupied[0];
            minoccupied_j = 0;
            // cout <<  "0 ";
            // for(int t = 0; t < occupied.size(); t++){
            //     cout << occupied[t] << " " ;
            // } 
            // cout << endl;
            // for(int j = 0; j < occupied.size(); j++ ){
            //     if(occupied[j] != 0){
            //         occupied[j] = occupied[j] - meetings[i][0];
            //         if(occupied[j] < 0){
            //             occupied[j]  = 0;
            //         }
            //     }
            // }

            for(int j = 0; j < occupied.size(); j++ ){
                if (occupied[j] <= meetings[i][0]){
                    occupied[j] = meetings[i][1];
                    res[j] = res[j] + 1;
                    zerowasthere = true;
                    break;
                }

                if(occupied[j] < minoccupied){
                    minoccupied = occupied[j];
                    minoccupied_j = j;
                }

                // cout <<  "1 ";
                // for(int t = 0; t < occupied.size(); t++){
                //     cout << occupied[t] << " " ;
                // } 

                // cout << endl;

                // cout << "minoccupied_j: " << minoccupied_j << "   minoccupied: " << minoccupied << endl;
            }
            
            if(!zerowasthere){
                occupied[minoccupied_j] += (meetings[i][1] - meetings[i][0]);
                res[minoccupied_j] = res[minoccupied_j] + 1;
            }

            // cout << "2 ";
            // for(int t = 0; t < occupied.size(); t++){
            //     cout << occupied[t] << " " ;
            // } 

            // cout << endl;
        }

        int resmax = 0;
        int r = 0;
        for(int i = 0; i < res.size(); i++ ){
            // cout << res[i] << endl;
            if(resmax < res[i]){
                resmax = res[i];
                r = i;
            }
        }

        return r;

        
    }
};