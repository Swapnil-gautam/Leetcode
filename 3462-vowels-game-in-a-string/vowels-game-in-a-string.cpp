class Solution {
public:
    bool doesAliceWin(string s) {


        int vowelCount = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
                vowelCount++;
            }
        }

        if(vowelCount == 0){
            return false;
        }

        // if(vowelCount%2 == 0){
        //     return true;
        // }
        return true;

    }
};

