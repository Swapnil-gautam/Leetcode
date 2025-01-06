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
    int dfs(TreeNode* root, int& max){
        if(root==NULL){
            return 0;
        }

        int l=1;
        int r=1;
        
        if(root->left != NULL){
            l = dfs(root->left, max)+1;
        }

        if(root->right != NULL){
            r = dfs(root->right, max)+1;
        }

        //cout  << root->val << " l: " << l << " r: " << r << endl;

        if(l>r){
            return l;
        }
        else{
            return r;
        }
    }

    int maxDepth(TreeNode* root) {
        int max;
        return dfs(root, max);
    }
};