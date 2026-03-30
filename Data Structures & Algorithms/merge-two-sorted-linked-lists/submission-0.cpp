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
        ListNode list3(0);
         ListNode* tail = &list3;

        ListNode* curr = list1;
        ListNode* cur = list2;
        while(curr != nullptr && cur != nullptr){
            if(curr -> val <= cur-> val){
                tail->next = curr;
                curr = curr->next;
            } else {
                tail->next = cur;
                cur = cur->next;
            }
            tail = tail->next;
        }

        tail->next = (curr != nullptr) ? curr : cur;


        return list3.next;
        
    }
};
