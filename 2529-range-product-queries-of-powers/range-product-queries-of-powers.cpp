class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        long long power = 1;
        int M = 1e9 + 7;
        while(n>0){
            if((n & 1) == 1){
                powers.push_back(power);
            }
            power = power*2;
            n = n >> 1;
        }

        // for(auto p: powers){
        //     cout << "p: " << p << endl;
        // }

        // cout << "****************: " << endl;

        // for(int i = 1; i < powers.size(); i++){
        //     powers[i] = powers[i] * powers[i-1];
        // }

        // for(auto p: powers){
        //     cout << "p: " << p << endl;
        // }

        vector<int> res;
        for(int i = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            long long prod = 1;
            // if(t1 == 0){
            //     res.push_back(powers[t2]%M);
            //     continue;
            // }

            for(int j = start; j <= end; j++){
                prod = (prod*powers[j])%M;
            }

            res.push_back(prod);

            // res.push_back((powers[t2]/powers[t1-1])%M);
        }

        return res;
    }
};