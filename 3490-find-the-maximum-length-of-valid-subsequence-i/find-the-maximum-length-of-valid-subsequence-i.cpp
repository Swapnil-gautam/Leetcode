class Solution {
public:

    // int solve(vector<int>& nums, int i, int need){
    //     if(i == nums.size()){
    //         return 0;
    //     }

    //     int take = 0;
    //     int notake = 0;

    //     if(need == (nums[i]%2)){

    //     }
    //     take = 1 + solve(nums, i+1 );
    //     notake = solve(nums, i+1 );

    //     return max(take, notake);

    // }

    int maximumLength(vector<int>& nums) {
        // int i = 0;
        // int need = 0;
        // return max(solve(nums, i, need), solve(nums, i, 1));

        int alleven = 0;
        int allodd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2 == 0){
                alleven++;
            }else{
                allodd++;
            }
        }


        int alternate = 1;
        int checkfor = 0; 
        if(nums[0]%2 == 0){
            checkfor = 1;
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]%2 == checkfor){
                alternate++;
                if(checkfor == 0){
                    checkfor = 1;
                }else{
                    checkfor = 0;
                }
            }
        }

        // int evenodd = 0;
        // checkfor = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i]%2 == checkfor){
        //         evenodd++;
        //         if(checkfor == 0){
        //             checkfor = 1;
        //         }else{
        //             checkfor = 0;
        //         }
        //     }
        // }

        return max(alternate, max(alleven, allodd));
    }
};




