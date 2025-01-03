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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *tempd =  new ListNode(0);
        ListNode *head = tempd;

        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                tempd->next = list1;
                list1 = list1->next;
            }else{
                tempd->next = list2;
                list2 = list2->next;
            }
            tempd = tempd->next;
        }

        if(list1!=NULL){
            tempd->next = list1;
        }

        if(list2!=NULL){
            tempd->next = list2;
        }

        return head->next;
    }
};