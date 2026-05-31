class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long ml = mass;
        for(int i = 0; i < asteroids.size(); i++){
            if( ml >= asteroids[i]){
                ml = ml + asteroids[i];
            }else{
                return false;
            }
        }

        return true;
    }
};