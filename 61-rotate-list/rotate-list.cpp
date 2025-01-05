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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int len = 1;
        ListNode *c = head;
        while(c->next!=NULL){
            c = c->next;
            len++;
        }

        k = k%len;
        if(k == 0){
            return head;
        }

        c->next = head;

        c = head;
        for(int i = 1; i < (len-k); i++){
            c = c->next;
        }

        ListNode *res = c->next;
        c->next = NULL;

        return res;
    }
};