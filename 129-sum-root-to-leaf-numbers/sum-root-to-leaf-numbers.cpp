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
    int dfs(TreeNode* root, int pathnum, int& res){
        if(root==NULL){
            return res;
        }

        pathnum = pathnum*10 + root->val;

        if(root->left==NULL && root->right==NULL){
            //cout << "pathnum: " << pathnum << endl;
            res = res + pathnum;
            // cout << "res: " << res << endl;
            // return res;
        }
        

        if(root->left!=NULL){
            dfs(root->left, pathnum, res);
        }

        if(root->right!=NULL){
            dfs(root->right,  pathnum, res);
        }

        return res;
    }

    int sumNumbers(TreeNode* root) {
        int pathnum = 0;
        int res = 0;
        return dfs(root, pathnum, res);
    }
};