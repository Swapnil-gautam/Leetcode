class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    
        
        vector<vector<int>> res;
        priority_queue<P, vector<P>,  greater<P>> pq; // pq
        set<pair<int, int>> visited;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        int n1 = nums1.size();
        int n2 = nums2.size();


        while(k-- && !pq.empty()){
            
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            res.push_back({nums1[i], nums2[j]});

            if(i+1 < n1 && (visited.find({i+1, j}) == visited.end())){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }

            if(j+1 < n2 && (visited.find({i, j+1}) == visited.end())){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }

        }

        return res;

    }
};