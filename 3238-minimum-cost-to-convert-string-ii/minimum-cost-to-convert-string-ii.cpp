// class Solution {
// public:
//     int dijistra(string source_substr, string target_substr, map<string, vector<pair<int, string>>> adj){
//         set<pair<int, string>> st;
//         st.insert(0, source_substr);

//         while(!st.empty()){
//             int curr_cost = st.begin().first;
//             string curr_node = st.begin().second;

//             st.pop();
//             if(curr_node = target_substr){
//                 return curr_cost;
//             }

//             for(const auto& ad: adj){
//                 st.insert({ad.first + curr_cost, ad.second});
//             }
//         }

//         return -1;
//     }
//     int solve(string source, string target, map<string, vector<pair<int, string>>> adj, set<int>lensubstr, int i){
//         if(i >= source.length()){
//             return 0;
//         }

//         for(int j = 0; j < lensubstr.size(); j++){
//             int l = lensubstr[j];
//             string source_substr = source[i:i+l];
//             string target_substr = target[i:i+l];
//             if(source_substr != target_substr){

//             }
//             solve(source, target, origional, changed, cost, lensubstr, i+l);
//         }
//     }

//     long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
//         int n = cost.size(); // origion & changed
//         int m = source.size(); // target
//         set<int>lensubstr;
//         for(int i = 0; i < n; i++){
//             lensubstr.insert(original[i].length());
//         }
//         lensubstr.insert(1);
//         int i = 0;
//         int l = 0;
//         int costsum = 0;
//         map<string, vector<pair<int, string>>> adj;
//         for(int i = 0; i < n; i++){
//             adj[original[i]].push_back({cost[i], changed[i]});
//         }

//         int res = solve(source, target, adj, lensubstr, i);

//         return -1;
//     }
// };



class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj; //Graph

    //start -> end -> anser
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr;
    string targetStr;
    set<int> validLengths;
    
    ll dijkstra(string& start, string& end) {

        if(dijkstraMemo[start].count(end)) {
            return dijkstraMemo[start][end];
        }

        //{cost, string}
        priority_queue<P, vector<P>, greater<P>> pq;
        //vector<int> result(n, INT_MAX)
        unordered_map<string, ll> result; //source to string ka cost stored
        result[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto &edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost+edgeCost, adjNode});
                }
            }
        }

        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;

        return dijkstraMemo[start][end] = finalCost;

    }

    ll solve(int idx) {
        if(idx >= sourceStr.length())
            return 0;
        if(dpMemo[idx] != -1)
            return dpMemo[idx];

        ll minCost = BIG_VALUE;

        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);
        
        for(auto &len : validLengths) {
            if(idx + len > sourceStr.length()) {
                break;
            }

            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);

            if(!adj.count(srcSub)) {
                continue;
            }

            ll minPathCost = dijkstra(srcSub, tgtSub);
            if(minPathCost == BIG_VALUE)
                continue;
            
            minCost = min(minCost, minPathCost + solve(idx+len));
        }

        return dpMemo[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dpMemo.assign(10001, -1);

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto &s : original) {
            validLengths.insert(s.length());
        }

        ll result = solve(0);

        return result == BIG_VALUE ? -1 : result;
    }
};

