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
        ListNode* push = dummy;
        
        int rm = 0;
        while(l1 != nullptr || l2 != nullptr){
            int left;
            if(l1 != nullptr){
                left = l1->val;
                l1 = l1->next;
            } else {
                left = 0;
            }
            int right;
            if(l2 != nullptr){
                right = l2->val;
                l2 = l2->next;
            } else {
                right = 0;
            }

            int sum = left + right + rm;
            int b = sum % 10;
            rm = sum / 10;
            push->next = new ListNode(b);
            push = push->next;
            
            
        }
        if(rm > 0){
            push->next = new ListNode(rm);
        }
        return dummy->next;
        
    }
};
