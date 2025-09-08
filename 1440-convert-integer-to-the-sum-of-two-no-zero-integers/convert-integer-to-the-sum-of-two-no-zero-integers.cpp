class Solution {
public:
    bool istherezero(int n){
        while(n > 0){
            if(n%10 == 0){
                return true;
            }
            n = n / 10;
        }

        return false;
        
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int a = 1;
        int b = n - a;
        while(istherezero(a) || istherezero(b)){
            a = a+1;
            b = n-a;
        }
        res.push_back(a);
        res.push_back(b);

        return res;
    }
};