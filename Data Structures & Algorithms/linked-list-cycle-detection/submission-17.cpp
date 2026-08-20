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
    bool hasCycle(ListNode* head) {
        if(head == nullptr){
            return false;
        }
        ListNode* rabbit = head;
        ListNode* turtle = head;

        while(rabbit->next != nullptr && rabbit->next->next != nullptr){
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if(rabbit->val == turtle->val){
                return true;
            }
            
        }
        return false;
    }
};
