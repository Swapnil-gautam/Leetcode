class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even_map_s1;
        unordered_map<char, int> odd_map_s1;

        unordered_map<char, int> even_map_s2;
        unordered_map<char, int> odd_map_s2;

        int n = s1.length();

        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                even_map_s1[s1[i]]++;
                even_map_s2[s2[i]]++;
            }else{
                odd_map_s1[s1[i]]++;
                odd_map_s2[s2[i]]++;
            }
        }

        if(even_map_s1.size() != even_map_s2.size() || odd_map_s1.size() != odd_map_s2.size()){
            return false;
        }

        for(auto& kvp : even_map_s1){
            if(even_map_s2.find(kvp.first) == even_map_s2.end()){
                return false;
            }
            if(even_map_s1[kvp.first] != even_map_s2[kvp.first]){
                return false;
            }
        }

        for(auto& kvp : odd_map_s1){
            if(odd_map_s2.find(kvp.first) == odd_map_s2.end()){
                return false;
            }
            if(odd_map_s1[kvp.first] != odd_map_s2[kvp.first]){
                return false;
            }
        }

        return true;

    }
};