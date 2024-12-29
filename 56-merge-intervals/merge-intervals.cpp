class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        if(n == 1){
            return intervals;
        }

        int starti = intervals[0][0];
        int endi = intervals[0][1];
        for(int i = 1; i <= n; i++){
            if(i == n){
                vector<int> temp; 
                temp.push_back(starti);
                temp.push_back(endi);
                res.push_back(temp);
            }else{
                if(intervals[i][0] > endi){
                    vector<int> temp; 
                    temp.push_back(starti);
                    temp.push_back(endi);
                    res.push_back(temp);
                    starti = intervals[i][0];
                    endi = intervals[i][1];
                }else{
                    starti = min(intervals[i][0], starti);
                    endi = max(intervals[i][1], endi);
                }
            }
        }
        return res;
    }
};