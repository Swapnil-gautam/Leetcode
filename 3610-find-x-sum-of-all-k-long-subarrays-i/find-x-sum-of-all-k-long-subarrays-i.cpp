class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> k_freq;

        int i = 0;
        int j = 0;
        vector<int> res;
        while(j < nums.size()){
            while(j - i  < k){
                cout << "nums[j]: " << nums[j] << endl;
                k_freq[nums[j]]++;
                j++;
            }
            priority_queue<pair<int, int>> max_pq; 
            for(auto& kf: k_freq){
                cout << "added to max pq: " << kf.second << " " <<  kf.first << endl;
                max_pq.push({kf.second, kf.first});
            }
            int sum = 0;
            int m = max_pq.size();
            int t = min(x, m);
            for(int i = 0; i < t; i++){
                cout << max_pq.top().first << " " << max_pq.top().second << endl;
                sum = sum + (max_pq.top().first*max_pq.top().second);
                max_pq.pop();
            }
            res.push_back(sum);
            k_freq[nums[i]]--;
            i++;
            cout << "i: " << i << endl;
        }
        return res;
    }
};

