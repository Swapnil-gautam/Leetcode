class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            // cout << floor(sqrt(nums[i])) << endl; 
            int divisorcount = 0;
            int sum = 0;
            // for(int j = 1; j <= floor(sqrt(nums[i])); j++){
            for(int j = 1; j*j <= (nums[i]); j++){
                if(nums[i]%j == 0){
                    // cout << "j: " <<  j << endl;
                    if(j == nums[i]/j){
                        divisorcount = divisorcount + 1;
                        sum = sum + j + nums[i]/j;
                    }else{
                        divisorcount = divisorcount + 2;
                        sum = sum + j + nums[i]/j;
                    }
                    
                }
                if(divisorcount > 4){
                    break;
                }
            }
            if(divisorcount == 4){
                // cout << "sum: " << sum << " nums[i]: " << nums[i] <<  endl;
                res = res + sum;
            }
        }
        return res;
    }
};