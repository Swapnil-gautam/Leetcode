class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landDuration.size();
        int m = waterDuration.size();
        int landmintime = INT_MAX;
        int landres = INT_MAX; 
        int watermintime = INT_MAX;
        int waterres = INT_MAX; 
        for(int i = 0; i < n; i++){
            landmintime = min(landmintime, landStartTime[i]+landDuration[i]);
        }

        for(int j = 0; j < m; j++){
            watermintime = min(watermintime, waterStartTime[j]+waterDuration[j]);
            landres = min(landres, max(landmintime, waterStartTime[j]) + waterDuration[j]);
        }

        for(int i = 0; i < n; i++){
            waterres = min(waterres, max(watermintime, landStartTime[i]) + landDuration[i]);
        }

        return min(landres, waterres);
    }
};