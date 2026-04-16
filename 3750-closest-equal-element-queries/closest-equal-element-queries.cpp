class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> res;
        int n = nums.size();

        // TLE
        // for(auto q : queries){
        //     int mindist = INT_MAX;
        //     int forw_idx = q;
        //     int back_idx = q;
        //     int target = nums[q];
        //     for(int i = 1; i < n; i++){
        //         forw_idx = (q + i)%n;
        //         back_idx = (q - i + n)%n;
        //         if(nums[forw_idx] == target){
        //             mindist = min(mindist, abs(forw_idx - q));
        //         }
        //         if(nums[back_idx] == target){
        //             mindist = min(mindist, n - abs(back_idx - q));
        //         }
        //     }

        //     if(mindist == INT_MAX){
        //         res.push_back(-1);
        //     }else{
        //         res.push_back(mindist);
        //     }
        // }   

        unordered_map<int, vector<int>> freq;

        for(int i = 0; i < n; i++){
            freq[nums[i]].push_back(i);
        }

        for(auto q : queries){
            int element = nums[q];
            vector<int>& vect = freq[element];
            if(freq.find(element) != freq.end() && vect.size() > 1){
                int mindist = n+1;
                // for(int i = 0; i < freq[nums[q]].size(); i ++){
                //     if(freq[nums[q]][i] != q){
                //         mindist = min(mindist, abs(q - freq[nums[q]][i]));
                //         mindist = min(mindist, n- abs(q - freq[nums[q]][i]));
                //     }
                // }
                int sz = vect.size();
                int pos = lower_bound(begin(vect), end(vect), q) - begin(vect);

                int right = vect[(pos+1)%sz];
                int d = abs(q - right);
                int circularDist = n-d;
                mindist = min({mindist, d, circularDist});

                int left = vect[(pos-1+sz)%sz];
                d = abs(q - left);
                circularDist = n-d;
                mindist = min({mindist, d, circularDist});

                res.push_back(mindist);
            }else{
                res.push_back(-1);
            }
        }

        return res;
    }
};