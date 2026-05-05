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
        
        if( head == NULL){
            return NULL;
        }
        int n = 0;
        ListNode* curr = head;

        // cout << curr->val << " " << curr->next->val << endl;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }
        // cout << "n: " << n << endl;
        k = k%n;
        if(k == 0){
            return head;
        }
        curr = head;
        ListNode* newhead;
        
        int i = 0;
        int t = n-k;
        while (i < t-1) {
            // cout << "i: " << i << " val: " << curr->val << endl;
            curr = curr->next;
            i = i+1;
        }

        // cout << " val: " << curr->val << endl;
        newhead = curr->next;
        curr->next = NULL;

        curr = newhead;
        // cout << newhead->val << endl;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = head;


        return newhead;

    }
    
};