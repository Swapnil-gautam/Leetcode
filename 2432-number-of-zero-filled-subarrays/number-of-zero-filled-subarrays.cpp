class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        long long zerocount = 0.0;
        int n = nums.size();
        long long sum = 0.0;
        while(i < n){
            if(nums[i] == 0){
                zerocount++;
            }else{
                if(zerocount != 0){
                    sum += ((zerocount * (zerocount+1))/2);
                }
                // cout << "zerocount: " << zerocount << " i: " << i << endl;
                zerocount = 0;
            }
            i++;
        }
        if(zerocount != 0){
            sum += ((zerocount * (zerocount+1))/2);
        }
        return sum;
    }
};
