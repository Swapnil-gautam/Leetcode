class Solution {
public:

    // recursion
    // int checkfor(unordered_map<int,int> mapn, int t, int count){
    //     //cout << "t: " << t << " count: " << count << endl; 
    //     if(mapn.find(t)!=mapn.end()){
    //         count++;
    //         count = checkfor(mapn, t+1, count);
    //     }
    //     return count;
    // }

    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxlen = 0;
    //     unordered_map<int,int> mapn;
    //     for(int i = 0; i<n; i++){
    //         mapn[nums[i]]++;
    //     }

    //     for(int i = 0; i<n; i++){
    //         int len = checkfor(mapn, nums[i]+1, 1);
    //         if(len > maxlen){
    //             maxlen = len;
    //         }
    //     }
    //     return maxlen;
    // }
    


    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        unordered_map<int,int> mapn;


        for(int i = 0; i<n; i++){
            mapn[nums[i]]= true;;
        }

        for(int i = 0; i<n; i++){
            if(mapn.find(nums[i]-1)!=mapn.end()){
                mapn[nums[i]] = false;
            }
        }

        for(int i = 0; i<n; i++){
            int count = 0;
            int j = 0;
            if(mapn[nums[i]] == true){
                while(mapn.find(nums[i]+j)!=mapn.end()){
                    j++;
                    count++;
                }
                if(count > maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};