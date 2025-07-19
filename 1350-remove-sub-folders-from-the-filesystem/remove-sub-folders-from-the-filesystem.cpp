class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> rootfolders;
        vector<string> results;
        string checkStr = "";
        sort(folder.begin(), folder.end());
        for(auto f: folder){
            // cout << "f: " << f << endl;
            bool isSubfolder = false;
            for(int i = 1; i < f.length(); i++){
                if(f[i] == '/' || i == f.length()-1){
                    if(i == f.length()-1){
                        checkStr = f.substr(0, i+1);
                    }else{
                        checkStr = f.substr(0, i);
                    }
                    // cout << "checkStr: " << checkStr << endl;
                    if(rootfolders.find(checkStr) != rootfolders.end()){
                        isSubfolder = true;
                        break;
                        // results.push_back(f);
                    }
                }
            }
            if(!isSubfolder){
                rootfolders.insert(f);
                results.push_back(f);
            }
        }
        // for(auto root: rootfolders){
        //     cout << "root: " << root << endl;
        // }
        return results;
    }
};