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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            int n = size;
            double sum = 0; 
            while(size>0){
                TreeNode* curr = qu.front();
                qu.pop();

                if(curr->left!=NULL){
                    qu.push(curr->left);
                }
                if(curr->right!=NULL){
                    qu.push(curr->right);
                }
                size--;
                sum = sum + curr->val;
            }
            double avg = sum / n;
            res.push_back(avg);
        }

        return res;
    }
};