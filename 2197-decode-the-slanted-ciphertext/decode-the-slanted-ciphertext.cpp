class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size()/rows;
        // cout << "n: " << n << endl;
        string res = "";
        for(int i = 0; i < n; i++){
            int idx = i;
            for(int j = 0; j < rows; j++){
                if(idx >= encodedText.size()){
                    break;
                }
                // res = res + encodedText[idx];
                res.push_back(encodedText[idx]); 
                idx = idx + n + 1;
            }
            // if(idx == encodedText.size()){
            //     break;
            // }
        }
        int m = res.length();
        int t = 0;
        for(int i = 0; i < m; i++){
            if (!res.empty() && res[m-1-i] == ' ') {
                res.pop_back(); // str is now "Hello"
            }else{
                break;
            }
        }
        return res;
    }
};