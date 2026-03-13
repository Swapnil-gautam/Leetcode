// class Solution {
// public:
//     long long timefunc(int workerTime, int n){
//         long long res = 0;
//         while(n > 0){
//             res = res + workerTime*n;
//             n--;
//         }
//         return res;
//     }
//     using pp = pair<int, int>;
//     long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//         // priority_queue<int, vector<pp>, greater<pp>> min_pq;
//         set<pp> timeSet;
        
//         int n = workerTimes.size();
//         vector<long long> resvec(n, 0);
//         for(int i = 0; i < workerTimes.size(); i++){
//             // min_pq.push(workerTimes[i], i);
//             timeSet.insert({workerTimes[i], i});
//         }
//         // for(pp t : timeSet){
//         //     cout << t.first << " " << t.second << endl;
//         // }
//         // int heightreduced = (mountainHeight / n) * n;
//         int heightremained = mountainHeight % n;

//         // cout << "heightreduced: " << heightreduced << " heightremained: " << heightremained << endl;
//         int t = mountainHeight / n;
//         // cout << "t: " << t << endl;
//         for(int i = 0; i < n; i++){
//             resvec[i] = timefunc(workerTimes[i], t);
//             // cout << resvec[i] << " " ;
//         }
//         // cout << endl;

//         while(heightremained > 0){
    
//             for(pp ts : timeSet){
//                 // cout << ts.first << " " << ts.second << endl;
//                 // cout << "resvec[ts.second]: " << resvec[ts.second] << endl;
//                 resvec[ts.second] = resvec[ts.second] + ts.first*(t+1);
//                 // cout << "resvec[ts.second]: " << resvec[ts.second] << endl;
//                 heightremained--;

//                 if(heightremained == 0){
//                     break;
//                 }
//             }
//         }

//         // for(int i = 0; i < n; i++){
//         //     cout << resvec[i] << " " ;
//         // }
//         sort(resvec.begin(), resvec.end(), greater<long long>());
//         // cout << resvec[0] << endl;
//         return resvec[0];

//         // long long maxTime = 0;
//         // long long heightreduced = 1;
//         // while(mountainHeight > 0){
//         //     for(pp t : timeSet){
//         //         // cout << t.first << " " << t.second << endl;
//         //         mountainHeight = mountainHeight - t.first*heightreduced;
//         //         if()
//         //     }
//         //     currsec++;
//         // }

//         // return maxTime;
//         // return 0;
//     }
// };


class Solution {
public:
    typedef long long ll;

    bool Check(ll mid, vector<int>& workerTimes, int mH) {
        ll h = 0;

        for(int &t : workerTimes) {
            h += (ll)(sqrt(2.0 * mid/t + 0.25) - 0.5);

            if(h >= mH) {
                return true;
            }
        }

        return h >= mH;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight+1)/2;

        ll result = 0;

        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(Check(mid, workerTimes, mountainHeight)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
