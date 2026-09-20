class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for( int i = 0; i < s.length(); i++){
            sum = sum + (123 - int(s[i]))*(i+1);
            // cout << (123 - int(s[i])) << endl;
        }
        return sum;
    }
};