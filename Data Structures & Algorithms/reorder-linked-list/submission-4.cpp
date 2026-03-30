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
        if(head == nullptr|| head->next == nullptr){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* save = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(save != nullptr){
            ListNode* tmp = save->next;
            save->next = prev;
            prev = save;
            save = tmp;
        }

        ListNode* red = prev;
        ListNode* blue = head;

        while(red != nullptr){
            ListNode* tmp1 = red->next;
            ListNode* tmp2 = blue->next;
            red->next = tmp2;
            blue->next = red;

            red = tmp1;
            blue = tmp2;
        }
    }
};
