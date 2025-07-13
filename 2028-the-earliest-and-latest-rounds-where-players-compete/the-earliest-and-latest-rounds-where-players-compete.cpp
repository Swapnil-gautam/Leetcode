// class Solution {
// public:
//     void solve(int n, int firstPlayer, int secondPlayer, vector<int> currplayers,vector<int>& res, int i,vector<int> winners, int round){
//         if(currplayers.size() == 1){
//             return;
//         }

//         if(currplayers[i] == firstPlayer && currplayers[n-1-i] == secondPlayer){
//             res.push_back(round);
//             return;
//         }

//         if(n % 2 != 0){
//             if(winners.size() == n/2+1){
//                 sort(winners.begin(), winners.end());
//                 for(auto w: winners){
//                     cout << w << " ";
//                 }
//                 cout << endl;
//                 currplayers = winners;
//                 n = winners.size();
//                 winners.clear();
//                 round = round+1;
//                 solve(n, firstPlayer, secondPlayer, winners, res, 0, winners, round);
//             }
//         }else{
//             if(winners.size() == n/2){
//                 sort(winners.begin(), winners.end());
//             }
//         }


//         if(n % 2 != 0){
//             if(i < n/2 ){
//                 if(currplayers[i] == firstPlayer || currplayers[i] == secondPlayer){
//                     winners.push_back(currplayers[i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }else if(currplayers[n-1-i] == firstPlayer || currplayers[n-1-i] == secondPlayer){
//                     winners.push_back(currplayers[n-1-i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }
//                 else{
//                     winners.push_back(currplayers[i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                     winners.push_back(currplayers[n-1-i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }
//             }else if(i == n/2){
//                 winners.push_back(currplayers[i]);
//                 solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                 winners.pop_back();
//             }
//         }else{
//             if(i < n/2 ){
//                 if(currplayers[i] == firstPlayer || currplayers[i] == secondPlayer){
//                     winners.push_back(currplayers[i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }else if(currplayers[n-1-i] == firstPlayer || currplayers[n-1-i] == secondPlayer){
//                     winners.push_back(currplayers[n-1-i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }
//                 else{
//                     winners.push_back(currplayers[i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                     winners.push_back(currplayers[n-1-i]);
//                     solve(n, firstPlayer, secondPlayer, currplayers, res, i+1, winners, round);
//                     winners.pop_back();
//                 }
//             }
//         }

//     };

//     vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
//         vector<int> currplayers(n,0);
//         for(int i = 0; i < n; i++){
//             currplayers[i] = i+1;
//         }
//         vector<int>res;
//         vector<int>winners;
//         int i = 0;
//         int round = 1;
//         solve(n, firstPlayer, secondPlayer, currplayers, res, i, winners, round);

//         return res;
//     }
// };


class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer; //P1
        int right = secondPlayer; //P2

        if(left == n - right + 1) {
            return {1, 1};
        }

        if(left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound  = n;
        int maxRound  = 1;
        int nextRoundPlayersCount = (n+1)/2;
        if(right <= nextRoundPlayersCount) { //Case-1 both on the same side
            int countLeft = left-1;
            int midCount  = right - left - 1;

            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft+1;
                    int pos2 = pos1 + survivorsMid + 1;
                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0]+1);
                    maxRound  = max(maxRound, tempResult[1]+1);
                }
            }
        } else { //case - 2 both on opposite end
            int fightsRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightsRight - left - 1;
            int remainMidCount = right - fightsRight - 1;

            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + (remainMidCount+1)/2 + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0]+1);
                    maxRound  = max(maxRound, tempResult[1]+1);
                }
            }
        }
        return {minRound, maxRound};
    }
};
