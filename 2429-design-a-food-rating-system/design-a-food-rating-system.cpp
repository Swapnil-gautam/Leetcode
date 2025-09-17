// class FoodRatings {
// public:
//     unordered_map<string, vector<string>> CuisineFood;
//     unordered_map<string, int> FoodtoRating;
//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for(int i = 0; i < foods.size(); i++){
//             CuisineFood[cuisines[i]].push_back(foods[i]);
//             FoodtoRating[foods[i]] = ratings[i];
//         }
//     }
    
//     void changeRating(string food, int newRating) {
//         FoodtoRating[food] = newRating;
//     }
    
//     string highestRated(string cuisine) {
//         string higherstRatingFood = "";
//         int foodRating = -1;
//         vector<string> temp = CuisineFood[cuisine];
//         for(int i = 0; i < temp.size(); i++){
//             if(foodRating < FoodtoRating[temp[i]]){
//                 foodRating = FoodtoRating[temp[i]];
//                 higherstRatingFood = temp[i];
//             }else if(foodRating == FoodtoRating[temp[i]]){
//                 if(temp[i] < higherstRatingFood){
//                     higherstRatingFood =  temp[i];
//                 }
//             }
//         }
//         return higherstRatingFood;
//     }
// };

// /**
//  * Your FoodRatings object will be instantiated and called as such:
//  * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
//  * obj->changeRating(food,newRating);
//  * string param_2 = obj->highestRated(cuisine);
//  */


class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; // higher rating first
            return a.second < b.second; // lexicographically smaller first
        }
    };

    unordered_map<string, int> FoodtoRating;
    unordered_map<string, string> FoodtoCuisine;
    unordered_map<string, set<pair<int,string>, cmp>> CuisineSet;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            FoodtoRating[foods[i]] = ratings[i];
            FoodtoCuisine[foods[i]] = cuisines[i];
            CuisineSet[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = FoodtoCuisine[food];
        int oldRating = FoodtoRating[food];
        // erase old entry
        CuisineSet[cuisine].erase({oldRating, food});
        // insert new entry
        CuisineSet[cuisine].insert({newRating, food});
        // update rating map
        FoodtoRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return CuisineSet[cuisine].begin()->second;
    }
};
