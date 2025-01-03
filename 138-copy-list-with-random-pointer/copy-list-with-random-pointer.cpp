/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead =  new Node(0);
        Node* res =  newhead;
        Node* newnode;
        unordered_map<Node* , Node*> nodetrack;

        Node* i = head;

        while(i!=NULL){
            newnode =  new Node(i->val);
            newhead->next = newnode;
            nodetrack[i] = newnode;
            // cout << "1: " << i << " : " << newnode << endl;
            i = i->next;
            newhead = newhead->next;
        }

        i = head;
        Node* j = res->next;

        while(i!=NULL){
            //cout << i->random << endl;
            if(i->random!=NULL){
                //cout << "2: " << i->random << " : " << nodetrack[i->random] << endl;
                j->random = nodetrack[i->random];
            }else{
                //cout << "else:" << endl;
                j->random = NULL;
            }
            i = i->next;
            j = j->next;
        }

        return res->next;
    }
};