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
        ListNode* l = head;
        int last = 0;
        while(l != nullptr){
           last++;
           l = l->next;
        }
        int idx = last - n;
        if(idx == 0){
            return head->next;
        }
        l = head;
        for(int i = 0; i < idx - 1; i++){
            l = l->next;
        }
        l->next = l->next->next;
        return head;
    }
};
