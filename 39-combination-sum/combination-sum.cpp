class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr, int& sum){
        if(sum > target){
            return;
        }

        if(sum == target){
            
            // sort(curr.begin(), curr.end());

            res.push_back(curr);

            // if(res.size()>0){
            //     for(int n: curr){
            //         cout << n  << " ";
            //     }
            //     cout << endl;
            //     sort(curr.begin(), curr.end());
            //     if(res[res.size()-1] != curr){
            //         for(int n: curr){
            //             cout << n  << " ";
            //         }
            //         cout << endl;
            //         cout << "*********" << endl;
            //         res.push_back(curr);
            //     }else{
            //         cout << "skip *********" << endl;
            //     }
            // }else{
            //     res.push_back(curr);
            // }

            return;
        }
        
        for(int i = 0; i < candidates.size(); i++){
            if(curr.size() > 0){
                if(curr[curr.size()-1] > candidates[i]){
                    continue;
                }
            }
            curr.push_back(candidates[i]);
            sum = sum + candidates[i];
            backtrack(candidates, target, res, curr, sum);
            sum = sum - candidates[i];
            curr.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, curr, sum);
        
        return res;
    }
};