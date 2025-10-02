class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptybottle = 0;
        int fullbottles = numBottles;
        int bottleDrunk = 0;
        while(fullbottles > 0 || emptybottle >= numExchange){
            // cout << "check" << endl;
            // cout << "fullbottles: " << fullbottles << endl;
            // cout << "emptybottle: " << emptybottle << endl;
            // cout << "numExchange: " << numExchange << endl;
            // cout << "bottleDrunk: " << bottleDrunk << endl;

            if(emptybottle >= numExchange){
                emptybottle = emptybottle-numExchange;
                fullbottles = fullbottles+1;
                numExchange = numExchange+1;
            }else{
                bottleDrunk = bottleDrunk + fullbottles;
                emptybottle = emptybottle + fullbottles;
                fullbottles = 0;
            }
        }

        return bottleDrunk;
    }
};