class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        while(carry > 0){
            if(i >=0){
                if(digits[i] != 9){
                    digits[i] = digits[i]+1;
                    carry = 0;
                }else{
                    digits[i] = 0;
                    carry = 1;
                    i--;
                }
            }else{
                digits.insert(digits.begin(), 1);
                carry = 0;
            }
        }

        return digits;
    }
};