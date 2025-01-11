// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     // bool dfs(TreeNode* root){
//     //     if(root == NULL){
//     //         return true;
//     //     }

//     //     if(root->left!=NULL){
//     //         if(root->left->val < root->val){
//     //             return true;
//     //         }else{
//     //             return false;
//     //         }
//     //     }

//     //     if(root->right!=NULL){
//     //         if(root->right->val > root->val){
//     //             return true;
//     //         }else{
//     //             return false;
//     //         }
//     //     }
        
//     //     // dfs(root->left);
//     //     // dfs(root->right);

//     //     return dfs(root->left) && dfs(root->right);
//     // }

//     bool isValidBST(TreeNode* root) {
//         // return dfs(root);
//         queue<TreeNode*> qu;
//         qu.push(root);

//         while(!qu.empty()){
//             int size = qu.size();
//             while(size > 0){
//                 TreeNode* curr = qu.front();
//                 qu.pop();
                
//                 if(curr->left != NULL){
//                     cout << curr->val << " " << curr->left->val << endl;
//                     if(curr->left->val >= curr->val){
//                         // cout << 
//                         return false;
//                     }else{
//                         qu.push(curr->left);
//                     }
//                 }
//                 if(curr->right != NULL){
//                     cout << curr->val << " " << curr->right->val << endl;
//                     if(curr->val >= curr->right->val){
//                         return false;
//                     }else{
//                         qu.push(curr->right);
//                     }
//                 }
//                 size--;
//             }
//         } 

//         return true;
//     }
// };




class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }    
};