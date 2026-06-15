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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* once = head;
        ListNode* twice = head;
        ListNode* prev = once;
        int n = 0;
        while( twice->next != NULL && twice->next->next != NULL){
            twice = twice->next->next;
            prev = once;
            once = once->next; 
            n = n+2;
        }
        if(twice->next != NULL){
            prev = once;
            once = once->next; 
        }

        prev->next = once->next;
        // once->next = once->next->next;

        return head;
    }
};