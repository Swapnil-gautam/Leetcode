class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> set1;
        set<int> set2;
        for(int i = 0; i < arr1.size(); i++){
            int t = arr1[i];
            while(t > 0){
                set1.insert(t);
                t = t/10;
            }
        }
        int max = 0;
        for(int i = 0; i < arr2.size(); i++){
            int t = arr2[i];
            while(t > 0){
                if(set1.find(t) != set1.end() && t > max){
                    max = t;
                }
                t = t/10;
            }
        }

        int count = 0;
        while(max > 0){
            count++;
            max = max/10;
        }

        return count;

    }
};