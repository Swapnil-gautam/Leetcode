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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            int n = qu.size();
            vector<int> level;
            while(n>0){
                TreeNode* curr = qu.front();
                qu.pop();
                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL){
                    qu.push(curr->right);
                }
                level.push_back(curr->val);
                n--;
            }
            res.push_back(level);
        }
        return res;
    }
};