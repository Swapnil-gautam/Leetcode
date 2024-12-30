class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> si; 

        for (auto s : tokens) {
            if(s!="+" && s!="-" && s!="/" && s!="*"){
                si.push(stoi(s));
            }else{
                int a = si.top();
                si.pop();
                int b = si.top();
                si.pop();
                int c;
                
                if(s=="+"){
                    c = b+a;
                }
                if(s=="-"){
                    c = b-a;
                }
                if(s=="/"){
                    c = b/a;
                }
                if(s=="*"){
                    c = b*a;
                }

                si.push(c);
            }
        }
        return si.top();
    }
};