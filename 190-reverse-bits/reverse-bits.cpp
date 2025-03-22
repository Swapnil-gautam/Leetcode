#include <iostream>
#include <string>
#include <cstdint>
#include <stdexcept>


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // vector<uint32_t> bi;
        // string bis;
        // cout << n/2 << endl;
        // while(n > 0){
        //     bi.push_back(n%2);
        //     bis = bis + to_string(n%2);
        //     n = n /2;
        // }

        // for(int i = 0; i < bis.size(); i++){
        //     cout << bis[i];
        // }
        // // static_cast<uint32_t>(bis)

        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            // cout << "1: " << ans << endl;
            ans = ans << 1;
            // cout << "2: " << ans << endl;
            if(n&1){ // if n mai 1 hai 
                ans = ans|1; // toh ans mai 1 daalo
            }
            n = n>>1;
        }
        return ans;
    }
};