class Solution {
public:

    bool solve(vector<int>& arr, vector<int>& vis, int i){
        if(i < 0 || i >= arr.size()){
            return false;
        }
        if(arr[i] == 0){
            return true;
        }
        if(vis[i] == 0){
            return false;
        }
        vis[i] = 0;
        return solve(arr, vis, i + arr[i]) || solve(arr, vis, i - arr[i]);

    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,-1);

        return solve(arr, vis, start);
    }
};