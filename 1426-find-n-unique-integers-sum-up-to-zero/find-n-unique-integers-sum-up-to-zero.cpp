class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n%2 != 0){
            res.push_back(0);
            n = n-1;
        }
        int i = 1;
        while(n != 0){
            res.push_back(i);
            res.push_back(-i);
            i = i+1;
            n = n-2;
        }

        return res;

    }
};