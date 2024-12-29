class Solution {
public:

    bool checkHappy(unordered_map<int, int>& seen, int n){

        if(seen.find(n)!=seen.end()){
            return false;
        }

        seen[n]++;

        int sum = 0;
        while(n>0){
            int r = n%10;
            n = n/10;
            sum = sum + r*r;
        }

        if(sum == 1){
            return true;
        }

        return checkHappy(seen, sum);
    }


    bool isHappy(int n) {
        unordered_map<int, int> seen;
        return checkHappy(seen, n);
    }
};