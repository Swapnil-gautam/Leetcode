class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for(int i = 0; i < points.size(); i++){
            unordered_map<float, int> dic;
            for(int j = i+1; j < points.size(); j++){
                float slope;
                if((points[j][0] - points[i][0]) != 0){
                    slope = (float)(points[j][1] - points[i][1]) / (float)(points[j][0] - points[i][0]);
                }else{
                    slope = INT_MIN;
                }
                dic[slope] = dic[slope]+1;
                // cout << "slope: " << slope << endl;
                // cout << "dic[slope] : " << dic[slope] << endl;
                res = max(res,dic[slope]+1);
            }
        }
        return res;
    }
};