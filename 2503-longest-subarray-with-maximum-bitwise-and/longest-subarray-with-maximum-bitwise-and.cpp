class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0;
        int freq = 1;
        int maxfreq = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }

        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == max && nums[i+1] == max){
                freq++;
            }else{
                freq = 1;
            }

            if(freq > maxfreq){
                maxfreq = freq;
            }
        }

        return maxfreq;
    }
};