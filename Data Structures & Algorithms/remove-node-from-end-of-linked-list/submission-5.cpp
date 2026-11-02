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
        ListNode dummy(0);
        ListNode* curr = &dummy;
        ListNode* h = head;
        int a = 0;
        while(h != nullptr){
            curr->next = h;
            curr = curr->next;
            h = h->next;
            a++;
        }
        curr = &dummy;
        for(int i = 0; i < a - n;i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return dummy.next;
    }
};
