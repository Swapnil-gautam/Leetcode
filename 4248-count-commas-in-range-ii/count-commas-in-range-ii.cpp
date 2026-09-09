class Solution {
public:
    long long countCommas(long long n) {
        
        long long t = n;
        int digi = 0;
        while(t > 0){
            digi++;
            t = t/10;
        }
        cout << digi << endl;
        if( digi < 4){
            return 0;
        }
        if( digi > 3 && digi < 7 ){
            return n-999;
        }else if(digi < 10){
            return (n-999)*2 - (999999 - 999);
        }else if(digi < 13){
            return (n-999)*3 - (999999 - 999)*2 - (999999999 - 999999);
        }else if(digi < 16){
            return (n-999)*4 - (999999 - 999)*3 - (999999999 - 999999)*2 - (999999999999 - 999999999);
        }
        long long d = 3;
        long long temp1 = (n-999)*5; 
        long long temp2 = (999000)* 4 ; 
        long long temp3 = (999000000)*d; 
        long long temp4 = (999000000000)*2; 
        return temp1 - temp2 - temp3 - temp4 - (999999999999999 - 999999999999);

    }
};