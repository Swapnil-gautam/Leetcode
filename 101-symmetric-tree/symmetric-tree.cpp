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
    bool IsIdentical(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }

        if(p == NULL || q == NULL || p->val != q->val){
            return false;
        }

        return IsIdentical(p->left, q->left) && IsIdentical(p->right, q->right);
    }

    TreeNode* invert(TreeNode* root){
        if(root == NULL){
            return NULL;
        }

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        if(root->left != NULL){
            invert(root->left);
        }

        if(root->right != NULL){
            invert(root->right);
        }

        return root;
    }

    bool isSymmetric(TreeNode* root) {
        return IsIdentical(root->left, invert(root->right));
    }
};