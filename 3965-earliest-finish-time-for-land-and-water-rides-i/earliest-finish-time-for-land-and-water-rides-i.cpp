class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(landStartTime[i] + landDuration[i] < waterStartTime[j]){
                    res = min(res, waterStartTime[j] +  waterDuration[j]);
                }else{
                    res = min(res, landStartTime[i] + landDuration[i] +  waterDuration[j]);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(waterStartTime[i] + waterDuration[i] < landStartTime[j]){
                    res = min(res, landStartTime[j] +  landDuration[j]);
                }else{
                    res = min(res, waterStartTime[i] + waterDuration[i] +  landDuration[j]);
                }
            }
        }

        return res;
    }
};
