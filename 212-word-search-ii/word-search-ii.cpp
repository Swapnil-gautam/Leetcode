class TrieNode{
    public:
    TrieNode* children[26];
    bool IsWordEnd;
    string word;

    TrieNode(){
        this->IsWordEnd = false;
        this->word = "";
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> result;
    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};

    void findWord(vector<vector<char>>& board, int i, int j, TrieNode* localroot){
        // cout << "i: " << i << " j: " << j << endl;
        if(i<0 || i>= board.size() || j < 0 || j >= board[0].size()){
            return;
        }

        if(board[i][j] == '$' || localroot->children[board[i][j] - 'a'] == NULL){
            return;
        }

        // cout << "board[i][j]: " << board[i][j] << endl;
        localroot = localroot->children[board[i][j]-'a'];


        if(localroot->IsWordEnd == true){
            // cout << "localroot->word: " << localroot->word << endl;
            result.push_back(localroot->word);
            localroot->IsWordEnd = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for(pair<int, int> dir : directions){
            int new_i = i + dir.first;
            int new_j = j + dir.second;
            findWord(board, new_i, new_j, localroot);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for(int i = 0; i < words.size(); i++){
            TrieNode* crawler = root;
            string word = words[i];
            // cout << "word: " << word << endl;
            for(int j = 0; j < words[i].length(); j ++){
                // cout << "word[j]: " << word[j] << endl;
                int idx = word[j] - 'a';
                if(crawler->children[idx] == NULL){
                    crawler->children[idx] = new TrieNode();
                }
                crawler = crawler->children[idx];
            }
            crawler->IsWordEnd = true;
            crawler->word = word;
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(root->children[board[i][j] - 'a']){
                    findWord(board, i, j, root);
                }
            }
        }
        
        return result;

    }
};