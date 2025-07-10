class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int gapstart = 0;
        vector<int> gapvector; 
        vector<int> meetingvector; 
        for(int i = 0; i < startTime.size(); i++){
            gapvector.push_back(startTime[i] - gapstart);
            meetingvector.push_back(endTime[i] - startTime[i]);
            gapstart = endTime[i];
        }

        gapvector.push_back(eventTime - gapstart);

        // for(int i = 0; i < gapvector.size(); i++){
        //     cout << gapvector[i] << " ";
        // }

        // cout << endl;

        // for(int i = 0; i < meetingvector.size(); i++){
        //     cout << meetingvector[i] << " ";
        // }

        // cout << endl;

        int maxfree = 0;
        // for(int i = 1; i < gapvector.size(); i++){
        //     maxfree = max(maxfree, (gapvector[i] + gapvector[i-1]));
        // }

        // unordered_map<int, int>gapfreq;

        vector<int> LeftMax(gapvector.size(), -1);
        vector<int> RightMax(gapvector.size(), -1);

        // for(int i = 0; i < gapvector.size(); i++){
        //     gapfreq[gapvector[i]]++;
        // }

        int left = gapvector[0];
        //cout << "LeftMax: ";
        for(int i = 0; i < gapvector.size(); i++){
            left = max(left, gapvector[i]);
            LeftMax[i] = left;
            //cout << left << " ";
        }
        //cout << endl;

        int right = gapvector[gapvector.size()-1];
        //cout << "RightMax: ";
        for(int i = gapvector.size()-1; i >= 0; i--){
            right = max(right, gapvector[i]);
            // RightMax.push_back(right);
            RightMax[i] = right;
            
        }

        // for(int i = 0; i < RightMax.size(); i++){
        //     cout << RightMax[i] << " ";
        // }

        // cout << endl;

        for(int i = 1; i < gapvector.size(); i++){

            maxfree = max(maxfree, (gapvector[i] + gapvector[i-1]));
            //cout << "i " << i << " meetingvector[i-1] " << meetingvector[i-1] << endl;
            if((i+1 <  gapvector.size())){
                //cout <<"i: " << i <<  " RightMax: " << RightMax[i+1] << " ";
                if(meetingvector[i-1] <= RightMax[i+1]){
                    maxfree = max(maxfree, (gapvector[i] + gapvector[i-1] + meetingvector[i-1]));
                }
            }

            // cout << endl;
            
            if((i-1 > 0)){
                //cout <<"i: " << i <<  " LeftMax: " << LeftMax[i-2] << " ";
                if( meetingvector[i-1] <= LeftMax[i-2]){
                    maxfree = max(maxfree, (gapvector[i] + gapvector[i-1] + meetingvector[i-1]));
                }
            }

            //cout << endl;
        }


        return maxfree;
    }
};