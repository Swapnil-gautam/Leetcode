class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // vector<int> res;
        // cout << "n: " << n << endl;
        for(int i = n-1; i >= 0; i--){
            // cout << "digits[i] : " << digits[i]  << endl;
            if(digits[i] == 9){
                // cout << "i: " << i << endl;
                digits[i] = 0;
                if(i == 0){
                    digits.insert(digits.begin(), 1);
                }
            }else{
                digits[i] = digits[i] + 1;
                break;
            }
            
        }

        return digits;
    }
};