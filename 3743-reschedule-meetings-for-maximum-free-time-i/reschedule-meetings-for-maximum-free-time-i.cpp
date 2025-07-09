class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        vector<int> gapvec;

        // int gapstart = 0;
        // int i = 0; 
        // int j = 0;
        // while(i <= eventTime){
        //     if(j < startTime.size()){
        //         //cout << "i:  " <<  i << " gapstart: " <<  gapstart << " j: " <<  j << endl;
        //         if(i == startTime[j]){
        //             cout << i - gapstart << endl;
        //             gapvec.push_back(i - gapstart);
        //         }

        //         if(i == endTime[j]){
        //             gapstart = i;
        //             j++;
        //             i--;
        //         }
        //     }

        //     if(i == eventTime){
        //         gapvec.push_back(i - gapstart);
        //     }

        //     i++;
        // }

        int p = 0;
        for(int i = 0; i < startTime.size(); i++){
            gapvec.push_back(startTime[i] - p);
            p = endTime[i];
        }

        gapvec.push_back(eventTime - p);

        if(gapvec.size() == 0){
            return 0;
        }

        int l = 0;
        int r = 0;
        int sum = 0;
        int maxsum = 0;

        while(r < gapvec.size()){
            if(r-l <= k){
                sum = sum + gapvec[r];
                r++;
            }else{
                sum = sum - gapvec[l];
                l++;
            }

            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};