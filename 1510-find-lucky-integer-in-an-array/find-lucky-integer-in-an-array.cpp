class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int lucky = -1;

        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
        }

        for(const auto& f : freq){
            if(f.first == f.second){
                lucky = max(lucky, f.first);
            }
        }

        return lucky;
    }
};