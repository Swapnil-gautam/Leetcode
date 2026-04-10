class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;

        for(int i= 0; i < nums.size(); i++){
            freq[nums[i]].push_back(i);
        }

        int mindist = INT_MAX; 
        for(auto p : freq){
            // cout << p.first << " " << p.second.size() << endl;
            if(p.second.size() >= 3){
                // cout << "check: " << p.first << " " << p.second.size() << endl;
                vector<int> temp = p.second;
                int a = 0; 
                int b = 0;
                int c = 0;
                for(int i = 0; i < p.second.size()-2; i++){
                    a = temp[i];
                    b = temp[i+1];
                    c = temp[i+2];
                    mindist = min(mindist, abs(a-b) + abs(b-c) + abs(c-a));
                }
            }
        }

        if(mindist == INT_MAX){
            return -1;
        }

        return mindist;
    }
};