class Solution {
public:

    void solve(int n, vector<string>&resvec, string prev){
        if(prev.length() == n+1){
            // cout << "prev: " << prev << " n+1: " << n+1 << " prev.length(): " << prev.length() << endl;
            if(prev == " "){
                return;
            }
            prev.erase(0, 1);
            resvec.push_back(prev);
            return;
        }

        if(prev.back()  != 'a'){
            solve(n, resvec, prev+"a");
        }
        if(prev.back()  != 'b'){
            solve(n, resvec, prev+"b");
        }
        if(prev.back()  != 'c'){
            solve(n, resvec, prev+"c");
        }
    }

    string getHappyString(int n, int k) {
        vector<string> resvec;
        string prev = " ";
        solve(n, resvec, prev);

        // for(string v : resvec){
        //     cout << v << endl;
        // }
        if(k > resvec.size()){
            return "";
        }

        return resvec[k-1];
    }
};