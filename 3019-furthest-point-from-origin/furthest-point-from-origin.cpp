class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int LR = 0; 
        int bl = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L'){
                LR++;
            }else if(moves[i] == 'R'){
                LR--;
            }else{
                bl++;
            }
        }
        return bl + (abs(LR));
    }
};