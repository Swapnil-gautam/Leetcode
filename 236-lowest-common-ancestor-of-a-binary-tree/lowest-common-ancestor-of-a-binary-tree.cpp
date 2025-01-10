/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // if(root!=NULL){
        //     cout << "root: "<< root->val << endl;
        // }else{
        //     cout << "root is NULL: " << endl;
        // }

        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* LCA_L = lowestCommonAncestor(root->left, p, q);
        TreeNode* LCA_R = lowestCommonAncestor(root->right, p, q);

        // if(LCA_L!=NULL ){
        //     cout << " LCA_L: " << LCA_L->val << endl;
        // }else{
        //     cout << " LCA_L is NULL:" << endl;
        // }

        // if(LCA_R!=NULL ){
        //     cout << " LCA_R: " << LCA_R->val << endl;
        // }else{
        //     cout << " LCA_R is NULL:" << endl;
        // }

        if(LCA_L && LCA_R){
            return root;

        }

        if(LCA_L == NULL){
            return LCA_R;
        }
        else{
            return LCA_L;
        }

        return root;

    }
};