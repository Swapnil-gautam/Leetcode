class Solution {
public:
    double solve(int A, int B, vector<vector<double>>& memo){
        // cout << "A: " << A << " B: " << B << endl;
        if(A <=0 && B > 0){
            return  1;
        }else if(A <=0 && B<= 0){
            return 0.5;
        }else if( A > 0 && B <= 0){
            return  0;
        }

        if(memo[A][B] != -1){
            return memo[A][B];
        }

        // double cas1P = 0.25 * solve(A-100, B);
        // cout <<"cas1P: " << cas1P << endl;
        // double cas2P = 0.25 * solve(A-75, B-25);
        // double cas3P = 0.25 * solve(A-50, B-50);
        // double cas4P = 0.25 * solve(A-25, B-75);

        return memo[A][B] = 0.25*(solve(A-100, B, memo) + solve(A-75, B-25, memo) + solve(A-50, B-50, memo) + solve(A-25, B-75, memo));
    }
    double soupServings(int n) {
        if(n > 4500){
            return 1;
        }
        vector<vector<double>> memo(n+1, vector<double>(n+1, -1));
        return solve(n, n, memo);
    }
};