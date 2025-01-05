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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *dummy = new ListNode(0, head);

        ListNode *p = dummy;
        ListNode *c = head;

        while(c!=NULL){
            if(c->next!=NULL && c->val == c->next->val){ // if - is agar aisa hai 
                while(c->next!=NULL && c->val == c->next->val){ // while - agar aisa hai 
                    c = c->next;
                }
                p->next = c->next;
            }else{
                p = c;
            }
            c = c->next;
        }
        return dummy->next;
    }
};