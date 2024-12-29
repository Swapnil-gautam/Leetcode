class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mapi;
        int n = nums.size();

        if(k<n){
            for(int i = 0; i<=k; i++){
                 cout << "k nums[i] entered: " << nums[i] << endl; 
                mapi[nums[i]]++;
            }

            for(int i = 0; i< n; i++){
                cout << " i: " << i << " nums[i] removed: " << nums[i] << endl;
                mapi[nums[i]] = mapi[nums[i]] - 1;
                if(mapi.find(nums[i])!=mapi.end()){
                    if(mapi[nums[i]]>0){
                        return true;
                    }
                }

                if(i+k+1 < n){
                    cout << " nums[i+k] added: " << nums[i+k+1] << endl;
                    mapi[nums[i+k+1]] = mapi[nums[i+k+1]] + 1;
                }
            }
        }else{
            for(int i = 0; i<n; i++){
                // cout << "n nums[i] entered: " << nums[i] << endl; 
                mapi[nums[i]]++;
            }

            for(int i = 0; i< n; i++){
                // if(nums[i] == nums[i+k]){
                //     return true;
                // }

                // cout << " i: " << i << " nums[i] removed: " << nums[i] << endl;
                mapi[nums[i]] = mapi[nums[i]] - 1;
                if(mapi.find(nums[i])!=mapi.end()){
                    if(mapi[nums[i]]>0){
                        return true;
                    }
                }

                if(i+k+1 < n){
                    // cout << " nums[i+k] added: " << nums[i+k+1] << endl;
                    mapi[nums[i+k+1]] = mapi[nums[i+k+1]] + 1;
                }
            }
        }

        return false;
    }
};