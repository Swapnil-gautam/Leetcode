class Solution {
public:
    // int gcd(int a, int b){
    //     while(b != 0){
    //         int temp = b;
    //         b = a%b;
    //         a = temp;
    //     }
    //     return a;
    // }

    // vector<int> replaceNonCoprimes(vector<int>& nums) {
    //     bool allgcdareone = false;
    //     while(!allgcdareone){
    //         int gcdres = 0;
    //         allgcdareone = true;
    //         // cout << "nums.size(): " << nums.size() << endl;            
    //         for(int i = 1; i < nums.size(); i++){
    //             if(nums[i] == nums[i-1] && nums[i] != 1){
    //                 //cout << "this is called: " << nums[i] << endl;
    //                 allgcdareone = false;
    //                 nums.erase(nums.begin() + i-1); 
    //                 break;
    //             }
    //             if(nums[i] > nums[i-1]){
    //                 gcdres = gcd(nums[i], nums[i-1]);
    //             }else{
    //                 gcdres = gcd(nums[i-1], nums[i]);
    //             }
    //             // cout << "i: " << i <<" gcdres: " << gcdres << endl;
    //             if(gcdres > 1){
    //                 allgcdareone = false;
    //                 long long a = nums[i];
    //                 long long b = nums[i-1];
    //                 long long temp = (a*b)/gcdres;
    //                 nums[i] = temp;
    //                 nums.erase(nums.begin() + i-1); 
    //                 break;
    //             }
    //         }
    //     }
    //     return nums;
    // }



    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;

        for(auto num: nums){

            while(!result.empty()){
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);

                if(GCD == 1){
                    break;
                }
                result.pop_back();
                int LCM = prev / GCD * curr;
                num = LCM;

            }
            result.push_back(num);
        }

        return result;
    }
};