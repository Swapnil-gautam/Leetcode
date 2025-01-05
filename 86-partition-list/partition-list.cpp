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

        bool firstlessthen = true;
        bool firstgreaterthen = true;

        ListNode* startless = NULL;
        ListNode* startgreater = NULL;

        while(i != NULL){
            if(i->val < x){
                if(firstlessthen){
                    startless = i;
                    firstlessthen = false;
                }
                lessthen->next = i;
                lessthen = lessthen->next;
            }else{
                if(firstgreaterthen){
                    startgreater = i;
                    firstgreaterthen = false;
                }
                greaterthen->next = i;
                greaterthen = greaterthen->next;
            }
            i = i->next;
        }

        greaterthen->next = NULL;
        lessthen->next = startgreater;       

        if(!firstlessthen){
            return startless;
        }else{
            return startgreater;
        }
    }
};