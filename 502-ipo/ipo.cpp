class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = capital.size();
        vector<pair<int, int>> CapProf;

        for(int i = 0; i < n; i++){
            CapProf.push_back({capital[i], profits[i]});
        }

        sort(begin(CapProf), end(CapProf));

        int i = 0;

        priority_queue<int> pq;

        while(k--){

            while(i < n && CapProf[i].first <= w){
                pq.push(CapProf[i].second);
                i++;
            }

            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }

};