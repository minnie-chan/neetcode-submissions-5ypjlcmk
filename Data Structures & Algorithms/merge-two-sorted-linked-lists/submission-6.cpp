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
        ListNode dummy(0);
        ListNode* push = &dummy;
        ListNode* top = list1;
        ListNode* bot = list2;

        while(top != nullptr && bot != nullptr){

            if(top->val == bot->val){
                push->next = bot;
                bot = bot->next;
            } else if(top->val < bot->val){
                push->next = top;
                top = top->next;
            } else {
                push->next = bot;
                bot = bot->next;
            }
            push = push->next;
        }
        if(top != nullptr){
            push->next = top;
            
        } else if(bot != nullptr){
            push->next = bot;    
        }

        return dummy.next;
    }
};
