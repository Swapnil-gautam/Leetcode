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
    // stack<TreeNode*> st;
    queue<TreeNode*> qu;
    TreeNode* lastNode;

    void updateQue(TreeNode* root){
        if(root == NULL ){
            return;
        }
        qu.push(root);
        updateQue(root->left);
        updateQue(root->right);
    }

    void emptyQue(TreeNode* root){
        TreeNode* curr = new TreeNode(0);
        while(!qu.empty()){
            curr->right = qu.front();
            curr->left = NULL;
            qu.pop();
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {

        updateQue(root);
        emptyQue(lastNode);
        
    }
};