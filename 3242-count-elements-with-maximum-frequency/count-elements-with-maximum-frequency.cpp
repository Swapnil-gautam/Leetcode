class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>Freq;
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            Freq[nums[i]]++;
            if(Freq[nums[i]] > max){
                max = Freq[nums[i]];
            }
        }

        int count = 0;
        for(auto& f: Freq){
            if(f.second == max){
                count = count+max;
            }
        }

        return count;
    }
};