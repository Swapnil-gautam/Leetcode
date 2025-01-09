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

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == NULL){
//             return NULL;
//         }
//         queue<Node*> level;
//         level.push(root);
//         int l = 1;
//         while(!level.empty()){
//             int size = level.size();
//             // cout << "l: " << l << " : ";
//             while(size>0){
//                 Node* n = level.front();

//                 level.pop();
//                 size--;
//                 // cout << n->val << " ";
//                 if(n->left != NULL){
//                     level.push(n->left);
//                 }

//                 if(n->right != NULL){
//                     level.push(n->right);
//                 }

//                 if(size>0){
//                     n->next = level.front();
//                 }else{
//                     n->next = NULL;
//                 }
                
//             }
//             // cout << endl;
//             l++;
//         }

//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* levelStart = root;

        while (levelStart != nullptr) {
            Node* curr = levelStart;
            Node* dummy = new Node(0); // Dummy node to represent the start of the next level
            Node* prev = dummy;

            while (curr != nullptr) {
                //cout << "curr1: "<< curr->val << endl;
                //cout << "prev1: "<< prev->val << endl;

                if (curr->left != nullptr) {
                    prev->next = curr->left;
                    prev = prev->next;
                    //cout << "prev2: "<< prev->val << endl;
                }

                if (curr->right != nullptr) {
                    prev->next = curr->right;
                    prev = prev->next;
                    //cout << "prev3: "<< prev->val << endl;
                }
                
                // cout << "curr2: "<< curr->val << endl;
                curr = curr->next;
                if(curr!=NULL){
                    // cout << "curr3: "<< curr->val << endl;
                }
            }

            levelStart = dummy->next; // Move to the next level
            // if(levelStart!=NULL){
            //     cout << "levelStart: " << levelStart->val << endl;
            // }
            delete dummy; // Free the dummy node
        }
        return root;
    }
};


// Follow-up:
// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
