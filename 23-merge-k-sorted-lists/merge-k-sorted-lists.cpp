// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         ListNode* dummy = new ListNode(0);
//         ListNode* head = dummy;
//         ListNode* min = lists[0];
//         int minIndex = 0;
//         while(lists.size() > 0){
//             min = lists[0];
//             int n = lists.size();
//             for(int j = 0; j < n; j++){
            
//                 if(lists[j] == NULL){
//                     cout << "list remove element" << endl;
//                     lists.erase(lists.begin() + j);
//                     // continue;
//                 }else{
//                     if(min != NULL){
//                         if(min->val >= lists[j]->val){
//                             cout << "if called: " << min->val << " : " << lists[j]->val << endl;
//                             min = lists[j];
//                             minIndex = j;
//                         }
//                     }
//                 }

//                 //cout << min->val << " : " << lists[j]->val << endl;
            
//                 // if(min->val >= lists[j]->val){
//                 //     min = lists[j];
//                 //     //cout << "if called: " << min->val << " : " << lists[j]->val << endl;
//                 //     minIndex = j;
//                 // }
//             }

//             cout << "*****" << endl;

//             if(min != NULL){
//                 cout << lists[minIndex]->val << " added and minIndex " << minIndex << endl;

//                 head->next = min;
//                 head = head->next;

//                 lists[minIndex] = lists[minIndex]->next;
//             }

//             cout << "*#*#*#**#*#*#" << endl;
//         }
//         return dummy->next;
//     }
// };






#include <vector>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }

    ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;
        ListNode* l1 = divideAndConquer(lists, left, mid);
        ListNode* l2 = divideAndConquer(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
};

