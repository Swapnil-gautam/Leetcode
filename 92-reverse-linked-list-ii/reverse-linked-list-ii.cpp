/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* curr){
        ListNode* p = NULL;
        ListNode* c = curr;
        ListNode* n = NULL;
        while(c != NULL){
            //cout << p->val << " : " << c->val << " : " << n->val << endl; 
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        //cout << p->val << " : " << endl;
        return p;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* current = head;
        ListNode* prev = NULL;

        while(count != left){
            prev = current;
            current = current->next;
            count++;
        }

        ListNode* start = current;
        while(count != right){
            current = current->next;
            count++;
        }

        ListNode* rest = current->next;
        current->next = NULL;

        ListNode* newHead = reverse(start);
        if (prev!=NULL){
            prev->next = newHead;

        }
        current = newHead;
        while(current->next!=NULL){
            current = current->next;
        }

        current->next = rest;

        if(left == 1){
            return newHead;
        }
        else{
            return head;
        }
    }
};