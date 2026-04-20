class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0; 
        int n = colors.size();
        int j = n-1;
        int dist = 0;
        while(i <= j){
            if(colors[j] != colors[0]){
                dist = max(dist, j);
            }
            if(colors[i] != colors[n-1]){
                dist = max(dist, n-1-i);
            }
            j--;
            i++;
        }

        return dist;
    }
};