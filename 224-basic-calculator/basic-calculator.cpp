// class Solution {
// public:
//     int calculate(string s) {

//         stack<int>ss;
//         bool pars = false;
//         bool fneg = false;
//         // s = "0+" + s;
//         for(int i = 0; i< s.length(); i++){
//             char ch = s[i];
//             if(ch != '+' && ch != '-' && ch != '(' && ch != ')' && ch != ' '){
//                 int num = ch - '0'; 
//                 if(fneg){
//                     num = -num;
//                 }
//                 cout << num << " ";
//                 ss.push(num);
//             }else{
//                 if(ch == '-'){
//                     fneg = true;
//                 }

//                 if(ch == '+'){
//                     fneg = false;
//                 }

//                 if(ch == '('){
//                     pars = true;
//                 }

//                 if(ch == ')'){
//                     pars = false;
//                 }
//             }
//         }

//         return 0;
//     }
// };



class Solution {
public:
    int calculate(string p) {
        stack < pair <int, int>> s;
        int n = 1, ans = 0;

        for (int i = 0; i < p.size(); i++) {
            if (isdigit(p[i])) {
                int r = 0;
                while (isdigit(p[i]) && i < p.size()) {
                    r = 10 * r + (p[i] - '0');
                    i++;
                }
                ans += (n * r);
                n = 1;
                i--;
            }
            else if (p[i] == '-') {
                n = -1 * n;
            }
            else if (p[i] == '(') {
                s.push({ans, n});
                ans = 0;
                n = 1;
            }
            else if (p[i] == ')') {
                ans = s.top().first + (s.top().second * ans);
                s.pop();
            }
        }
        return ans;
    }
};