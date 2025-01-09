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
private:
    int postindex;
    unordered_map<int , int> inmap;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }
        for(int i = 0; i < inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        postindex = postorder.size()-1;
        return build(postorder, 0, postindex);
    }

    TreeNode* build(vector<int>& postorder, int start, int end) {
        if (start > end) return nullptr;

        int rootval = postorder[postindex];
        TreeNode* root = new TreeNode(rootval);
        postindex--;
        int mid = inmap[rootval];
        
        root->right = build(postorder, mid+1, end);
        root->left = build(postorder, start, mid-1);
        return root;
    }
};