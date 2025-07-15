class Solution {
public:
    bool isValid(string word) {
        bool min3 = true;
        bool onlydna = true;
        int v = 0;
        int c = 0;
        bool onev = false;
        bool onec = false;

        if(word.length() < 3){
            min3 = false; 
            return false;
        }

        for(auto w : word){
            // cout << (int)w << endl;
            int asci = w;

            if((asci >= 48  && asci <= 57) || (asci >= 65  && asci <= 90) || (asci >= 97  && asci <= 122)){
                if( w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U' || w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' ){
                    v++;
                }else{
                    if(!(asci >= 48  && asci <= 57)){
                        // cout << w << endl;
                        c++;
                    }
                }
            }else{
                onlydna = false;
                return false;
            }
        }

        if(v > 0){
            onev = true;
        }
        if(c > 0){
            onec = true;
        }
        return min3 & onlydna & onev & onec;
    }
};

        