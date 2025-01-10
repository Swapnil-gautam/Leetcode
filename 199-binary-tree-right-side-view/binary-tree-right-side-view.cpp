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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        if(root==NULL){
            return res;
        }
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            while(size>0){
                TreeNode* curr = qu.front();
                
                qu.pop();

                if(curr->left != NULL){
                    qu.push(curr->left);
                }

                if(curr->right != NULL){
                    qu.push(curr->right);
                }

                if(size == 1){
                    // cout << curr-> val << endl;
                    res.push_back(curr-> val);
                }
                size--;
            }
        }

        return res;
    }
};