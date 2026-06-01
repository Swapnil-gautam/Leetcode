class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());
        int sum = 0;
        for(int i = 0; i < cost.size(); i++){
            // cout << cost[i] << endl;
            if( ((i+1) % 3) == 0){
                // cout << cost[i] << endl;
                continue;
            }
            sum = sum + cost[i];
        }
        return sum;
    }
};