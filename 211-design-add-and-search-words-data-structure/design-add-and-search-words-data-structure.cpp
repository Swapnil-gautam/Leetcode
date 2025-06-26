class TrieNode{
    public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        endOfWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* crawler = root;
        cout << word << endl;
        cout << crawler->children[1] << endl;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL){
                crawler->children[idx] = new TrieNode();
            } 
            crawler = crawler->children[idx];
        }
        crawler->endOfWord = true;
    }

    bool searchUtil(string word, TrieNode* newroot){
        TrieNode* crawler = newroot;
        
        // cout <<"word1: " <<  word << endl;
        for(int i = 0; i < word.length(); i++){
            // cout <<"word[i]: " <<  word[i] << endl;
            if(word[i] != '.'){
                int idx = word[i] - 'a';
                if(crawler->children[idx] == NULL){
                    // cout << "return false called" << endl;
                    return false;
                } 
                crawler = crawler->children[idx];
            }else{
                for(int j = 0; j < 26; j++){
                    if(crawler->children[j] != NULL){
                        // cout <<"word2: "<< word.substr(i+1, word.length() - i) << endl;
                        if(searchUtil(word.substr(i+1, word.length() - i),crawler->children[j])){
                            // cout <<"true called: "<< endl;
                            return true;
                        }
                    } 
                }
                return false;
            }
        }
        return crawler->endOfWord;
    }
    
    bool search(string word) {
        // cout <<"**************: " << endl;
        return searchUtil(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */