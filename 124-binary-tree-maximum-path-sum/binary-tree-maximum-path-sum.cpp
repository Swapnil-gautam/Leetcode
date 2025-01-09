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
    int mx = INT_MIN;
    
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        // if(root->right==NULL && root->left==NULL){
        //     return root->val;
        // }

        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        // if(root->left!=NULL){
        //     l = dfs(root->left, mx);
        // }

        // if(root->right!=NULL){
        //     r = dfs(root->right, mx);
        // }

        // mx = max(mx, root->val);
        // mx = max(mx, l);
        // mx = max(mx, r);
        // mx = max(mx, root->val + l);
        // mx = max(mx, root->val + r);
        mx = max(mx, root->val + l + r);

        // cout << "root->val: " << root->val << " l: " << l << " r: " << r << " mx: " << mx << endl;


        // return mx;
        return root->val + max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};