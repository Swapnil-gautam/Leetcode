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
    ListNode* reverse(ListNode* c){
        ListNode* p = NULL;
        ListNode* n = NULL;
        while(c!=NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }

        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* i = head;
        ListNode* lastend = new ListNode(0);
        ListNode* res = lastend;
        bool firstTime = true;

        while(i != NULL){

            int count = 1;
            ListNode* start = i;

            while(count != k){
                if(i == NULL){
                    break;
                }
                i = i->next; 
                count++;
            }

            //currently start point to the start of the LindeList that we want to reverse 
            // i point to the last node that need to be reversed

            if(i == NULL){
                lastend->next = start;
                break;
            }

            ListNode* nextstart = i->next;
            i->next = NULL;

            // Here we break the link of last node ( i.e. i ) and make it point to NULL
            // and before doing that we save the i->next that will be our next start

            lastend->next = reverse(start);

            if(firstTime){
                res = lastend->next;
                firstTime = false;
            }

            lastend = i;
            while(lastend->next != NULL){
                lastend = lastend->next;
            }
            
            i = nextstart;
        }

        return res;
    }
};