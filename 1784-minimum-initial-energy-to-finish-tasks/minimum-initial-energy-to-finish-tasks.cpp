// class Solution {
// public:
//     int minimumEffort(vector<vector<int>>& tasks) {

//         sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
//             int diffA = a.first - a.second;
//             int diffB = b.first - b.second;

//             if (diffA != diffB) {
//                 return diffA < diffB; // Sort by difference first
//             }
//             return a.second < b.second; // Tie-breaker: Second element gets preference
//         });

//         for( int i = 0; i < tasks.size(); i++){

//         }
//     }
// };



class Solution {
public:

    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(auto &task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);


        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
