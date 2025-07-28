class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        stack<int> uniqnums;
        uniqnums.push(nums[n-1]);

        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] != uniqnums.top()){
                // cout << "nums[i]: " << nums[i] << endl;
                uniqnums.push(nums[i]);
            }
        }

        // if(uniqnums.empty()){
        //     return 0;
        // }
        int prev = uniqnums.top();
        uniqnums.pop();
        if(uniqnums.empty()){
            return 0;
        }
        int curr = uniqnums.top();
        uniqnums.pop();
        int next = 0;
        while(!uniqnums.empty()){
            next = uniqnums.top();
            uniqnums.pop();
            if((curr > prev && curr > next) || (curr < prev && curr < next)){
                count++;
            }
            prev = curr;
            curr = next;
        }
        return count;
    }
};