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
        ListNode* blue = head;
        int red = 0;
        while(blue != nullptr){
            red++;
            blue = blue->next;
        }
        int purple = red - n;
        if(purple == 0){
            return head->next;
        }
        ListNode* curr = head;
        for(int i = 0; i < purple - 1; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};
