class Solution {
public:
    string simplifyPath(string path) {
        stack<string>words;
        stack<string>res;
        // stack.push('/')
        string word;
        string resword;
        path = path + "/";

        for (auto ch : path) {
            if(ch == '/'){
                if(word.length()!=0){
                    if(word == ".." && !words.empty()){
                        words.pop();
                    }
                    else if(word != "." && word != ".."){
                        words.push(word);
                    }
                    word = "";
                }
            }else{
                word = word + ch;
            }
        }

        while(!words.empty()){
            // cout << words.top() << endl;
            res.push(words.top());
            words.pop();
        }

        while(!res.empty()){
            //cout << res.top() << endl;
            // res.push(words.top());
            resword = resword + "/" + res.top();
            res.pop();
        }

        if(resword == ""){
            resword = "/";
        }

        return resword;
    }
};