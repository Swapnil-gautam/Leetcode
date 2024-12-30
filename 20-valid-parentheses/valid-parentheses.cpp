class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i=0; i<s.length(); i++){
            
            if(ss.empty()){
                ss.push(s[i]);
                continue;
            }

            if(s[i] =='(' || s[i] =='[' || s[i] =='{' ){
                ss.push(s[i]);
                continue;
            }

            if((ss.top()=='(' && s[i] == ')') || (ss.top()=='{' && s[i] == '}') || (ss.top()=='[' && s[i] == ']')){
                ss.pop();
            }else{
                return false;
            }

        }

        if(ss.empty()){
            return true;
        }

        return false;
    }
};