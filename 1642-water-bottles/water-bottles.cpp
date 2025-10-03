class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int FullBottles= numBottles;
        int EmptyBottles= 0;
        int DrunkBottles = 0;

        while(FullBottles > 0){
            // Drink all
            DrunkBottles = DrunkBottles + FullBottles;
            EmptyBottles = EmptyBottles + FullBottles;
            FullBottles = 0;

            // Exchange
            FullBottles = FullBottles + EmptyBottles/numExchange;
            EmptyBottles = EmptyBottles%numExchange;
        }

        return DrunkBottles;
    }
};