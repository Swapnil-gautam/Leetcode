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
    int n = 0;
    // stack<TreeNode* root> st;
    void count(TreeNode* root) {
        if(root == NULL){
            return;
        }
        n = n+1;
        count(root->left);
        
        count(root->right);
    }

    int countNodes(TreeNode* root) {
        count(root);
        return n;
    }
};