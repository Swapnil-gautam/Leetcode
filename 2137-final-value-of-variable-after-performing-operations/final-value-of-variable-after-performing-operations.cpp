class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int var = 0;
        for(auto op : operations){
            if(op == "X++" || op == "++X"){
                var++;
            }else{
                var--;
            }
        }
        return var;
    }
};