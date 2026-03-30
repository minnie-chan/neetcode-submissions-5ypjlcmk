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
        ListNode* dummy = new ListNode();
        ListNode* track = dummy;

             int remainder = 0;
        while(l1 != nullptr || l2 != nullptr){
            int a; 
            if(l1 != nullptr){
                a = l1->val;
            } else {
                a = 0;
            }
            int b;
            if(l2 != nullptr){
                b = l2->val;
            } else {
                b = 0;
            }
            int sum = a + b + remainder;
            int ones = sum % 10;
            remainder = sum / 10;
            track->next = new ListNode(ones);
            track = track->next;
            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        } 
        if(remainder > 0){
            track->next = new ListNode(remainder);
        }
        return dummy->next;
    }
};
