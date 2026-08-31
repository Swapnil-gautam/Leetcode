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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        vector<int> cp;
        int i = 1;

        while(curr != NULL & curr->next != NULL){
            if(prev->val < curr->val && curr->val > curr->next->val){
                cp.push_back(i);
            }else if(prev->val > curr->val && curr->val < curr->next->val){
                cp.push_back(i);
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        // cout << cp.size() << endl;
        if( cp.size() < 2){
            return {-1, -1};
        }

        int mindist = cp[1] - cp[0];
        int maxdist = cp[cp.size()-1] - cp[0];

        for(int j = 1; j < cp.size(); j++){
            if((cp[j] - cp[j-1]) < mindist){
                mindist = cp[j] - cp[j-1];
            }
        }

        return {mindist, maxdist};


    }
};