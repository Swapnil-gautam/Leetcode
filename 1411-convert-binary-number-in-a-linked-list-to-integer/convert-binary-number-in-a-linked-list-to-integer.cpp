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
    int getDecimalValue(ListNode* head) {
        int base = 1;
        int num = 0;
        vector<int> binaryNum;
        while(head != nullptr){
            //cout << head->val << endl;
            binaryNum.push_back(head->val);
            head = head->next;
        }

        for(int i = binaryNum.size()-1; i >= 0; i--){
            num = num + (binaryNum[i] * base);
            base = base*2;
        }
        return num;
    }
};