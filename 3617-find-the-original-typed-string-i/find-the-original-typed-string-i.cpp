class Solution {
public:
    int possibleStringCount(string word) {

        // unordered_map<char, int> freq;
        // int UniqueElementCount = 0;
        // int sum = 0;

        // for(int i = 0; i < word.length(); i++){
        //     if(freq[word[i]]<1){
        //         UniqueElementCount++;
        //     }
        //     freq[word[i]] = freq[word[i]] + 1;
        // }

        // for(const auto& pair : freq){
        //     sum = sum + pair.second;
        // }

        // return (sum - UniqueElementCount + 1);

        int i = 1;
        int count = 0;
        char prev = word[0];
        while(i < word.length()){
            if(prev == word[i]){
                count++;
            }
            prev = word[i];
            i++;
        }
        
        return count + 1;
    }
};