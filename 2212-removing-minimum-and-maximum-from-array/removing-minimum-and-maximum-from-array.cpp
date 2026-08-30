class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int pos_max = 0;
        int pos_min = 0;
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(maxnum < nums[i]){
                maxnum = nums[i];
                pos_max = i;
            }
            if(minnum > nums[i]){
                minnum = nums[i];
                pos_min = i;
            }
        }
        cout << "maxnum: " <<  maxnum << " pos_max: " << pos_max << endl;
        cout << "minnum: " <<  minnum << " pos_min: " << pos_min << endl;
        int Lp = min(pos_max, pos_min)+1;
        int Rp = max(pos_max, pos_min)+1;

        cout << "Lp: " << Lp << endl; 
        cout << "Rp: " << Rp << endl; 


        int midpos = nums.size()/2;
        cout << "midpos: " << midpos << " nums.size(): " << nums.size() << endl;
        // if(pos_max < midpos && pos_min < midpos){
        //     return max(pos_max, pos_min);
        // }
        // if(pos_max > midpos && pos_min > midpos){
        //     return max(pos_max, pos_min);
        // }
        if(Lp == Rp){
            int t = nums.size() - Lp;
            return min(Lp, t) + 1;
        }


        int a = nums.size() - Lp + 1;
        int b = Lp + (nums.size() - Rp) + 1;

        return min(min(a, b), Rp);

        // if(Lp < midpos && Rp > midpos){
        //     return Lp + (nums.size() - Rp) + 1;
        // }else if(Lp < midpos && Rp <= midpos){
        //     cout << "return rp" << endl;
        //     return Rp;
        // }else if(Lp >= midpos && Rp > midpos){
        //     return nums.size() - Lp +1;
        // }
        // return -1;
    }
};