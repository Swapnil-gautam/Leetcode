class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int max_enery = INT_MIN;

        for(int i = energy.size()-1; i >= 0; i--){
            if(i <= energy.size()-1-k ){
                energy[i] = energy[i]+energy[i+k];
            }
            
            if(max_enery < energy[i]){
                max_enery = energy[i];
            }
        }        
        // for(int i = 0; i < energy.size(); i++){
        //     if(max_enery < energy[i]){
        //         max_enery = energy[i];
        //     }
        // }
        return max_enery;
    }
};

