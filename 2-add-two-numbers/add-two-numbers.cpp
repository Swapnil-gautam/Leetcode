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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* ans = res;
        int q = 0;

        while(l1!=NULL || l2!=NULL || q){
            int sum = q;

            if(l1!=NULL){
                sum = sum+l1->val;
                l1 = l1->next;
            }

            if(l2!=NULL){
                sum = sum+l2->val;
                l2 = l2->next;
            }

            // cout << sum << endl;
            q = sum/10;
            int r = sum%10;

            res->next= new ListNode(r);
            res = res->next;
        }

        ans = ans->next;
        return ans;
    }
};