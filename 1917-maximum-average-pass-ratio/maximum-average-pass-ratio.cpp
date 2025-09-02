class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        double maxAverage = 0.0;
        priority_queue<pair<double, int>, vector<pair<double, int>>> minHeap;

        for(int i = 0; i < classes.size(); i++){
                double n = classes[i][0];
                double d = classes[i][1];

                double curraverage = n/d;

                double n_new = classes[i][0] + 1;
                double d_new = classes[i][1] + 1;

                double newaverage = n_new/d_new;

                double diffaverage = newaverage - curraverage;

                minHeap.push({diffaverage, i});                
            }

        while(extraStudents > 0){
            pair<double, int> topPair = minHeap.top();
            minHeap.pop();
            int i = topPair.second;
            classes[i][0] = classes[i][0] + 1;
            classes[i][1] = classes[i][1] + 1;

            double n = classes[i][0];
            double d = classes[i][1];

            double curraverage = n/d;

            double n_new = classes[i][0] + 1;
            double d_new = classes[i][1] + 1;

            double newaverage = n_new/d_new;

            double diffaverage = newaverage - curraverage;

            minHeap.push({diffaverage, i});
            

            extraStudents--;
        }

        for(int i = 0; i < classes.size(); i++){
            double n = classes[i][0];
            double d = classes[i][1];
            maxAverage = maxAverage + (n / d);
            // cout << "(n / d): " << (n / d) << endl;
        }
        maxAverage = maxAverage / classes.size();
        return maxAverage;
    }
};

