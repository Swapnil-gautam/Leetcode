/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> parents;
        set<int> child;
        unordered_map<int, TreeNode*> valtonode;
        int root;
        for(int i = 0; i < descriptions.size(); i++){
           int p = descriptions[i][0];
           int c = descriptions[i][1];
           int l = descriptions[i][2];
           parents.insert(p);
           child.insert(c);
           if(valtonode.find(p) == valtonode.end()){
                valtonode[p] = new TreeNode(p);
           }
           if(valtonode.find(c) == valtonode.end()){
                valtonode[c] = new TreeNode(c);
           }
           if(l == 1){
                valtonode[p]->left = valtonode[c];
           }else{
                valtonode[p]->right = valtonode[c];
           }
        //    cout << "p: " << p << " " << endl;
        //    if(parents.find(c) != parents.end()){
        //         cout << "c: " << c << " " << endl;
        //         parents.erase(c); 
        //    }
        }



        // while(paresnts.size() > 0){
        //     cout << paresnts.top();
        //     paresnts.pop()
        // }

        for (const auto& pp : parents) {
            // std::cout << pp << " ";
            if(child.find(pp) != child.end()){
                parents.erase(pp); 
            }
        }
        cout << endl;
        for (const auto& pp : parents) {
            // std::cout << pp << " ";
            // if(child.find(pp) != child.end()){
            //     parents.erase(pp); 
            // }
            root = pp;
        }

        return valtonode[root];
    }
};