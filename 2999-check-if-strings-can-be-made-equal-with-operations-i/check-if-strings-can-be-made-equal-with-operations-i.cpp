class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        char temp = s1[2];
        s1[2] = s1[0];
        s1[0] = temp;
        if(s1 == s2){
            return true;
        }
        temp = s1[3];
        s1[3] = s1[1];
        s1[1] = temp;
        if(s1 == s2){
            return true;
        }
        temp = s1[2];
        s1[2] = s1[0];
        s1[0] = temp;
        if(s1 == s2){
            return true;
        }
        return false;

    }
};