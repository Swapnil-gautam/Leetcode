/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> level;
        level.push(root);
        int l = 1;
        while(!level.empty()){
            int size = level.size();
            // cout << "l: " << l << " : ";
            while(size>0){
                Node* n = level.front();

                level.pop();
                size--;
                // cout << n->val << " ";
                if(n->left != NULL){
                    level.push(n->left);
                }

                if(n->right != NULL){
                    level.push(n->right);
                }

                if(size>0){
                    n->next = level.front();
                }else{
                    n->next = NULL;
                }
                
            }
            // cout << endl;
            l++;
        }

        return root;
    }
};