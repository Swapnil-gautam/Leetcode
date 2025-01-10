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
    queue<int> qu;

    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }

        dfs(root->left);
        qu.push(root->val);
        dfs(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        while(!qu.empty() && (k-1)){
            //cout << qu.front() << endl;
            qu.pop();
            k--;
        }


        return qu.front();
    }
};