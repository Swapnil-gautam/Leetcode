class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mindist = n+1;

        if(words[startIndex] == target){
            return 0;
        }

        int i = startIndex+1;
        while(i != startIndex){
            if(words[i] == target){
                mindist = min(mindist, abs(startIndex-i));
            }
            i = i+1;
            i = i % n;
        }
        // cout << "mindist: " << mindist << endl;

        i = ((startIndex-1)+n)%n;
        while(i != startIndex){
            // cout << "i: " << i << endl;
            if(words[i] == target){
                mindist = min(mindist, n-abs(startIndex-i));
            }
            i = i-1;
            i = (i+n) % n;
        }

        if(mindist == n+1){
            return -1;
        }
        return mindist;
    }
};