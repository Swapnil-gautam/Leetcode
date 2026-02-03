class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        stack<int> p_set;
        stack<int> q_set;
        bool curr_inc = false;
        bool prev_inc = true;

        if(nums.size()<4){
            return false;
        }

        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) {
                curr_inc = true;
            } else if (nums[i] > nums[i+1]) {
                curr_inc = false;
            } else {
                return false;
            }

            if (curr_inc == true && prev_inc == false) {
                q_set.push(i);
            } else if (curr_inc == false && prev_inc == true && i != 0) {
                p_set.push(i);
            }

            prev_inc = curr_inc;
        }

        // while (!p_set.empty()) {
        //     cout << "p_set: " << p_set.top() << endl;
        //     p_set.pop();
        // }

        // while (!q_set.empty()) {
        //     cout << "q_set: " << q_set.top() << endl;
        //     q_set.pop();
        // }

        if(p_set.size() == 1 && q_set.size() == 1){
            int p = p_set.top();
            int q = q_set.top();
            if(p < q){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        return true;
    }
}
;