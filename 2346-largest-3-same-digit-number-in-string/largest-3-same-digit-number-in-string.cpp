class Solution {
public:
    string largestGoodInteger(string num) {
        if(num.size() < 3){
            return "";
        }
        string res = "";
        for(int i =  1; i < num.size()-1; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                //cout << "check: " << num[i] << endl;
                if(res == ""){
                    res = res + num[i-1] + num[i] + num[i+1];
                }
                else if(res[0] < num[i]){
                    res[0] = num[i-1];
                    res[1] = num[i];
                    res[2] = num[i+1]; 
                }
            }
        }
        return res;
    }
};




