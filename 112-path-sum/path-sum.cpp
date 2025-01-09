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
    bool dfs(TreeNode* root, int targetSum, int pathsum){
        if(root->left == NULL && root->right == NULL){
            pathsum = pathsum + root->val;
            //cout << "root: " << root->val << " pathsum: " << pathsum << endl;
            if(pathsum == targetSum){
                return true;
            }else{
                return false;
            }
        }
        pathsum = pathsum + root->val;
        //cout << "root: " << root->val << " pathsum: " << pathsum << endl;
        bool l = false;
        bool r = false;
        if(root->left!= NULL){
            l = dfs(root->left, targetSum, pathsum);
        }

        if(root->right!= NULL){
            r = dfs(root->right, targetSum, pathsum);
        }
        
        return l || r;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int pathsum = 0;
        return dfs(root, targetSum, pathsum);
    }
};