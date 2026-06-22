class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // a - 1, b - 1, l - 2, o - 2, n - 1
        vector<int> ablon(5, 0);
        for(auto t : text){
            if(t == 'a'){
                ablon[0]++;
            }
            else if(t == 'b'){
                ablon[1]++;
            }
            else if(t == 'l'){
                ablon[2]++;
            }
            else if(t == 'o'){
                ablon[3]++;
            }
            else if(t == 'n'){
                ablon[4]++;
            }
        }

        ablon[2] = ablon[2]/2;
        ablon[3] = ablon[3]/2;
        int ans = INT_MAX;
        for(auto i : ablon){
            ans = min(ans, i);
        }

        return ans;
    }
};