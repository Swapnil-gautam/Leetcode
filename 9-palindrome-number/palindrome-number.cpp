class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false;
        }
        
        int temp = x;
        long div = 1;

        while(temp > 10*div){
            div = div * 10;
        }

        temp = x;

        while(temp > 0){
             
            if(temp%10 != temp/div ){
                // cout << "nd: " << nd << endl;
                // cout << "temp%10: " << temp%10 << endl;
                // cout << "temp: " << temp << endl;
                // cout << "div: " << div << endl;
                // cout << "temp/(div): " << temp/(div) << endl;
                return false;
            }

            temp = (temp%div)/10;
            div = div/100;

            // cout << temp;
        }


        return true;
    }
};