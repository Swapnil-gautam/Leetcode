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
    ListNode* FindMiddle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode;
        ListNode* start = dummy;
        while(left != NULL && right != NULL){
            if(left->val > right->val){
                dummy->next = right;
                dummy = dummy->next;
                right = right->next;
            }else{
                dummy->next = left;
                dummy = dummy->next;
                left = left->next;
            }

            if(left==NULL){
                dummy->next = right;
            }

            if(right==NULL){
                dummy->next = left;
            }

        }
        return start->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }

        ListNode* middle = FindMiddle(head);
        // cout << middle->val << endl;

        ListNode* temp = middle->next;
        middle->next = NULL;
        middle = temp;
        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);

        return merge(left, right);
    }
};