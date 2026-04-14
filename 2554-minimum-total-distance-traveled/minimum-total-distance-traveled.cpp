class Solution {
public:
    vector<vector<long long>> dp;
    
    long long solve(int ri, int fi, vector<int>& robot, vector<int>& factory){  
        if(ri >= robot.size()){
            return 0;
        }
        if(fi >= factory.size()){
            return 1e12;
        }

        if(dp[ri][fi] != -1){
            return dp[ri][fi];
        }

        long long take = abs(robot[ri] - factory[fi]) + solve(ri+1, fi+1, robot, factory);
        long long nottake = solve(ri, fi+1, robot, factory);

        return dp[ri][fi] = min(take, nottake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int m = factory.size();
        int n = robot.size();

        vector<int> position;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < factory[i][1]; j++){
                position.push_back(factory[i][0]);
            }
        }

        m = position.size();

        dp.resize(n, vector<long long>(m,-1));

        return solve(0,0,robot,position);
    }
};