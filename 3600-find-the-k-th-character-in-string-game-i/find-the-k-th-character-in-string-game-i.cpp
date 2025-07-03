class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){
            string newword = "";
            for(int i = 0; i < word.length(); i++){
                // cout << word[i] - 'a' << endl;
                int vali = word[i]+1;
                if(vali == 122){
                    vali = 97;
                }
                char next = vali;
                // cout << " next: " << next << endl;
                newword = newword + next;
            }
            // cout << " newword: " << newword << endl;
            word = word + newword;
        }
        // cout << " word: " << word << endl;
        return word[k-1];
    }
};