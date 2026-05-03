class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        // unordered_map<char, int> s_map;
        // unordered_map<char, int> g_map;

        // for(int i = 0; i < s.length(); i++){
        //     s_map[s[i]]++;
        //     g_map[goal[i]]++;
        // }

        // for (const auto& kvps : s_map) {
        //     if(g_map.find(kvps.first) != g_map.end()){
        //         cout << "g_map: " << kvps.first << " kvps.second: " << kvps.second << endl;
        //         if(kvps.second != g_map[kvps.first]){
        //             return false;
        //         }
        //     }else{
        //         return false;
        //     }
        // }      
        string curr = s;
        string temp;
        for(int i = 0; i < s.length(); i++){
            temp = curr.substr(1, s.length()-1) + curr[0];
            if( temp == goal){
                return true;
            }
            curr = temp;
        }

        return false;
    }
};