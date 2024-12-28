class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, vector<int>> smap;
        map<char, vector<int>> tmap;

        for(int i = 0; i < s.size(); i++){
            

            smap[s[i]].push_back(i);
            tmap[t[i]].push_back(i);

            // if(smap.find(s[i])!=smap.end()){
            //     smap[s[i]]++;
            // }else{
            //     smap[s[i]].push_back(i);
            // }

            // if(tmap.find(t[i])!=tmap.end()){
            //     tmap[t[i]]++;
            // }else{
            //     tmap[t[i]] = 1;
            // }


            //cout << s[i] << " : " << smap[s[i]][0] << " : " << t[i] << " : " << tmap[t[i]][0] << endl;
            if(smap[s[i]]!=tmap[t[i]]){
                return false;
            }
        }
        return true;
    }
};