class Solution {
public:
    int reversei(int num){
        int newnum = 0;
        int r = 0;
        while(num > 0){
            r = num%10;
            num = num/10;
            newnum = newnum*10 + r;
        }
        return newnum;
    }



    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < nums.size(); i++){
            pos[nums[i]].push_back(i);
        }

        int mindist = nums.size()+1;
        for(int i = 0; i < nums.size(); i++){
            int revnum = reversei(nums[i]);
            //cout << "nums: " << nums[i] << " revnum: " << revnum << endl;
            if(pos.find(revnum) != pos.end()){
                vector<int>& posvect = pos[revnum];
                // for(int j = 0; j < posvect.size(); j++){
                //     if(posvect[j] > i){
                //         mindist = min(mindist, posvect[j] - i);
                //     }
                // }
                auto it = std::upper_bound(posvect.begin(), posvect.end(), i);
                
                if(it != posvect.end() && *it > i){
                    // cout << "*it: " << *it << endl; 
                    mindist = min(mindist, *it - i);
                }
            }
        }

        if(mindist == nums.size()+1){
            return -1;
        }
        return mindist;
    }
};