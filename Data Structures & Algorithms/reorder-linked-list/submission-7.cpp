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
        ListNode* s = head;
        ListNode* f = head;
        ListNode* b = nullptr;

        while (f != nullptr && f->next != nullptr) {
            b = s;
            s = s->next;
            f = f->next->next;
        }
        if(b == nullptr){
            return;
        }

        ListNode* prev = nullptr;
        b->next = nullptr;

        while (s != nullptr) {
            ListNode* save = s->next;
            s->next = prev;
            prev = s;
            s = save;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;

        while (l1 != nullptr && l2 != nullptr) {
            ListNode* save1 = l1->next;
            ListNode* save2 = l2->next;

            if (save1 != nullptr) {
                l2->next = save1;
            } else {
                l2->next = save2;
            }
            
            l1->next = l2;

            l1 = save1;
            l2 = save2;
        }
    }
};
