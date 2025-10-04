class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxArea = 0;
        int w = 0;
        int h = 0;
        while(i < j ){
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;

            w = j - i;
            h = min(height[i], height[j]);

            // cout << "w: " << w << endl;
            // cout << "h: " << h << endl;

            maxArea = max(maxArea, w*h);

            if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxArea;
    }
};