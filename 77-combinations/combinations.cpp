class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int n, int k, int i, vector<int> curr){
        curr.push_back(i);

        if(curr.size() == k){
            result.push_back(curr);
            return;
        }

        for(int j = i+1; j<=n; j++){
            // cout << "i: " << i << " j: " << j << endl;
            backtrack( n,  k,  j, curr);
        }
        // cout << "**********" << endl;
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;

        for(int i = 1; i <= n; i++){
            backtrack( n,  k,  i, curr);
        }

        return result;
    }
};