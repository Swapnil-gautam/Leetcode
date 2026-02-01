class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto &ch: letters){
            if(target -'a' < ch - 'a'){
                return ch;
            }
        }
        return letters[0];
    }
};

