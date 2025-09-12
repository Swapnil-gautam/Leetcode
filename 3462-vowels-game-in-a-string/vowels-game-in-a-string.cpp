class Solution {
public:
    bool doesAliceWin(string s) {


        int vowelCount = 0;
        int lastOddVowel = 0;
        int lastEvenVowel = 0;
        int chance = 0;
        // while(s.length() != 0){

        //     for(int i = 0; i < s.length(); i++){
        //         if(s[i]='a' || s[i]='e'|| s[i]='i'|| s[i]='o'|| s[i]='u'){
        //             vowelCount++;
        //             if(vowelCount%2 == 0){
        //                 lastEvenVowel = i;
        //             }else{
        //                 lastOddVowel = i;
        //             }
        //         }
        //     }

        //     if(chance%2 == 0){
        //         cout << lastOddVowel
        //         s = s.substr(lastOddVowel, s.length() - lastOddVowel);
        //     }else{
        //         s = s.substr(lastEvenVowel, s.length() - lastEvenVowel);
        //     }

        // }


        for(int i = 0; i < s.length(); i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
                vowelCount++;
                // if(vowelCount%2 == 0){
                //     lastEvenVowel = i;
                // }else{
                //     lastOddVowel = i;
                // }
            }
        }

        if(vowelCount == 0){
            return false;
        }

        if(vowelCount%2 == 0){
            return true;
        }
        
        return true;

    }
};

