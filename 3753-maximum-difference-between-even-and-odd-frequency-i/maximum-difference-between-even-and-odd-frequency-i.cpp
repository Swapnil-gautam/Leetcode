class Solution {
public:

    int maxDifference(string s) {
        unordered_map<char, int> freq;
        int oddmax = 1;
        int evenmin = 100;
        for(int i = 0; i < s.length(); i++){
            freq[s[i]]++; 
        }

        for (const auto& pair : freq) {
            // cout << pair.first << ": " << pair.second << endl;
            if(pair.second % 2 != 0){
                if(oddmax < pair.second){
                    oddmax = pair.second;
                }
            }else{
                if(evenmin > pair.second){
                    evenmin = pair.second;
                }
                 
            }
        }

        return oddmax - evenmin;
    }
};