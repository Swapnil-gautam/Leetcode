class Solution {
public:

    int solveA(vector<vector<int>>&fruits, int Ai, int Aj, int n, vector<vector<int>>& memoA){
        if(Ai< 0 || Aj < 0 || Ai>= n || Aj >= n){
            return 0;
        }
        if(Aj < Ai){
            return 0;
        }

        if(Ai == n-2 && Aj == n-1){
            return memoA[Ai][Aj] = fruits[Ai][Aj];
        }

        if( memoA[Ai][Aj] != -1){
            return  memoA[Ai][Aj];
        }

        int pointsL = fruits[Ai][Aj] + solveA(fruits, Ai+1,Aj-1,  n, memoA);
        int pointsS = fruits[Ai][Aj] + solveA(fruits, Ai+1,Aj,  n, memoA);
        int pointsR = fruits[Ai][Aj] + solveA(fruits, Ai+1,Aj+1,  n, memoA);
        return  memoA[Ai][Aj] = max(max(pointsL, pointsS), pointsR);
    }

    int solveB(vector<vector<int>>&fruits, int Bi, int Bj, int n, vector<vector<int>>& memoB){
        if(Bi< 0 || Bj < 0 || Bi>= n || Bj >= n){
            return 0;
        }
        if(Bj > Bi){
            return 0;
        }

        if(Bi == n-1 && Bj == n-2){
            return memoB[Bi][Bj] = fruits[Bi][Bj];
        }

        if( memoB[Bi][Bj] != -1){
            return  memoB[Bi][Bj];
        }

        int pointsL = fruits[Bi][Bj] + solveB(fruits, Bi-1,Bj+1,  n, memoB);
        int pointsS = fruits[Bi][Bj] + solveB(fruits, Bi,Bj+1,  n, memoB);
        int pointsR = fruits[Bi][Bj] + solveB(fruits, Bi+1,Bj+1,  n, memoB);
        return memoB[Bi][Bj] = max(max(pointsL, pointsS), pointsR);
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int Ai = 0;
        int Aj = n-1;

        int Bi = n-1;
        int Bj = 0;

        int points = 0;

        for(int i = 0; i < n; i++){
            points += fruits[i][i];
            fruits[i][i] = -1;
        }

        int t = (n/2);
        int MaxL = t-1;
        vector<vector<int>> memoA(n, vector<int>(n,-1));
        int pointsA = solveA(fruits, Ai,Aj, n, memoA);
        vector<vector<int>> memoB(n, vector<int>(n,-1));
        int pointsB = solveB(fruits, Bi,Bj, n, memoB);

        // cout << "points: " << points << endl;
        // cout << "pointsA: " <<  pointsA << endl;
        // cout << "pointsB: " <<  pointsB << endl;


        return points + pointsA + pointsB;
    }
};


