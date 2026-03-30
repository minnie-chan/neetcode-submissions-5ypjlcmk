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
        ListNode* MEOWTALICA = &dummy;
        ListNode* curr_one = list1;
        ListNode* curr_two = list2;

        while(curr_one != nullptr && curr_two != nullptr){
            if(curr_one -> val < curr_two -> val){
                MEOWTALICA  -> next = curr_one;
                curr_one = curr_one -> next;
            } else {
                 MEOWTALICA -> next = curr_two;
                 curr_two = curr_two -> next;
            }
            MEOWTALICA = MEOWTALICA -> next;
        }
        MEOWTALICA -> next = (curr_one != nullptr) ? curr_one : curr_two;

        return dummy.next;
    }
};
