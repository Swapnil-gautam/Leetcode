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
    ListNode* partition(ListNode* head, int x) {
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }
        ListNode* lessthen = new ListNode(0);
        ListNode* greaterthen = new ListNode(0);
        ListNode* i = head;

        ListNode* startless = lessthen;
        ListNode* startgreater = greaterthen;

        while(i != NULL){
            if(i->val < x){
                lessthen->next = i;
                lessthen = lessthen->next;
            }else{
                greaterthen->next = i;
                greaterthen = greaterthen->next;
            }
            i = i->next;
        }

        greaterthen->next = NULL;
        lessthen->next = startgreater->next;  

        return startless->next;     
    }
};