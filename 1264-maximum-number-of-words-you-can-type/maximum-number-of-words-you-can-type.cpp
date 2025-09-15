class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> bset;
        for(auto b : brokenLetters){
            bset.insert(b);
        }
        bool allgood = true;
        int goodcount = 0;
        string word = "";
        for(auto t: text){
            if(t != ' '){
                word = word + t;
                if(bset.find(t) != bset.end()){
                    //cout << "t found: " << t << endl;
                    allgood = false;
                }

            }else{
                //cout << "word: " << word << " allgood: " << allgood << endl;
                if(allgood == true){
                    goodcount++;
                }
                word = "";
                allgood = true;
            }
        }
        //cout << "word: " << word << " allgood: " << allgood << endl;
        if(allgood == true){
            goodcount++;
        }
        return goodcount;
    }
};