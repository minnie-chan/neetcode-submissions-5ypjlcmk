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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* push = dummy;
        ListNode* move = head;
        while(n > 0){
            move = move->next;
            n--;
        }
        while(move != nullptr){
            push = push->next;
            move = move->next;
        }
        push->next = push->next->next;
        return dummy->next;
    }
};
