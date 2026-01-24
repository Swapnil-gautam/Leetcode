class Solution {
public:
    // int minimumPairRemoval(vector<int>& nums) {
    //     vector<int> res;
    //     stack<int> st;
    //     int count = 0;

    //     st.push(nums[nums.size()-1]);
    //     for(int i = nums.size()-2; i >= 0; i--){
    //         if(nums[i] > st.top()){
    //             int t = nums[i];
    //             while(!s.empty() && t > st.top()){
    //                 t = t + st.top();
    //                 st.pop();
    //                 count++;
    //             }
    //             st.push(t);
    //         }else{
    //             st.push(nums[i]);
    //         }
    //     }
    //     return count;
    // }


    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long>temp(n);
        vector<int>prevIndex(n);
        vector<int>nextIndex(n);
        set<pair<long long, int>> minpairset;
        int badpair = 0;
        int count = 0;

        for(int i = 0; i<n; i++){
            temp[i] = nums[i];
            prevIndex[i] = i-1;
            nextIndex[i] = i+1;
            if(i != n-1){
                if(nums[i]>nums[i+1]){
                    badpair++;
                }
                minpairset.insert({nums[i]+nums[i+1], i});
            }
        }

        while(badpair > 0){
            int first = minpairset.begin() -> second;
            int second = nextIndex[first];

            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            
            minpairset.erase(minpairset.begin());

            if(temp[first] > temp[second]){
                badpair--;
            }


            if(first_left >=0){
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]){
                    badpair--;
                }
                else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]){
                    badpair++;
                }
                
            }

            if(second_right < n){
                if(temp[second] > temp[second_right] && (temp[first] + temp[second]) <= temp[second_right]){
                    badpair--;
                }else if(temp[second] <= temp[second_right] && (temp[first] + temp[second]) > temp[second_right]){
                    badpair++;
                }
                
            }


            if(first_left >=0){
                minpairset.erase({temp[first_left] + temp[first], first_left});
                minpairset.insert({temp[first_left] + temp[first] + temp[second], first_left});
                
            }

            if(second_right < n) {
                minpairset.erase({temp[second] + temp[second_right], second});
                minpairset.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] = temp[first] + temp[second];
            count++;

        }
        return count;
    }
};


