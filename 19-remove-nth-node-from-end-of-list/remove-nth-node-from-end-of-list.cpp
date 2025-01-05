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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode* curr = head;

        while(curr->next!=NULL){
            curr = curr->next;
            len++;
        }

        int k = len - n;
        //cout << k << " : " << len << " : " << n <<  endl;
        curr = head;
        
        if(k == 0){
            return head->next;
        }

        int i = 1;
        ListNode* prev = new ListNode(0);
        prev->next = curr;

        while(i < k+1){
            prev = curr;
            curr = curr->next;
            i++;
        }

        // if(curr->next !=){
        //     prev->next = curr->next;
        // }

        if(curr->next != NULL){
            prev->next = curr->next;
        }else{
            prev->next = NULL;
        }

        // cout << prev->val << " : " << curr->val << endl;
        return head;
    }
};