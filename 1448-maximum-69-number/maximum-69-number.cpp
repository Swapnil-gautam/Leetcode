class Solution {
public:
    int maximum69Number (int num) {
        string nums = to_string(num);
        // cout << nums << endl;
        for(int i = 0; i < nums.length(); i++){
            if(nums[i] == '6'){
                nums[i] = '9';
                break;
            }
        }
        // cout << nums << endl;
        int res = stoi(nums);
        return res;
    }
};