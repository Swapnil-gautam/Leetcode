class Solution {
public:
    bool isvalid(int num){
        bool newnum = false;
        while(num > 0){
            int t = num%10;
            // cout << "t: " << t << endl;
            if(t == 3 || t == 4 || t == 7){
                return false;
            }
            if(t == 2 || t == 5 || t == 6 || t == 9){
                newnum = true;
            }
            num = num/10;
        }
        
        if(newnum == false){
            return false;
        }
        return true;
    }

    int rotatedDigits(int n) {
        // numbert that dont have 3 4 7
        int count = 0;
        for(int i = 1; i < n+1; i++){
            if(isvalid(i)){
                count++;
            }
        }
        return count;
    }
};