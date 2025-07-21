// class Solution {
// public:
//     string makeFancyString(string s) {
//         int i = 0;
//         int n = s.length();
//         // int erasetillnow = 0;
//         // vector<int> deli;
//         if(n < 3){
//             return s;
//         }
//         string res = "";
//         while(i < n-2){
//             if(!((s[i] == s[i+1])  &&  (s[i+1] == s[i+2]))){
//                 // deli.push_back(i);
//                 res = res + s[i];
//             }
//             // else{
//             //     res = res + s[i];
//             // }
//             i++;
//         }

//         res = res + s[n-2] + s[n-1];

//         // for(int i = 0; i < deli.size(); i++){
//         //     s.erase(deli[i]);
//         //     // erasetillnow++;
//         //     // cout << deli[i]<< endl;
//         // }

//         return res;
//     }
// };



class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string result = "";

        result.push_back(s[0]);
        int freq = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == result.back()) {
                freq++;
                if(freq < 3) {
                    result.push_back(s[i]);
                }
            } else {
                result.push_back(s[i]);
                freq = 1;
            }
        }

        return result;
    }
};