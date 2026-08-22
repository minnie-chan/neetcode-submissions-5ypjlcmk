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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* s = slow->next;
        slow->next = nullptr;

        ListNode* curr = s;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode* fr = head;

        while(prev != nullptr){
            ListNode* tmp = fr->next;
            ListNode* tmp2 = prev->next;

            fr->next = prev;
            prev->next = tmp;

            fr = tmp;
            prev = tmp2;
        }
    }
};
