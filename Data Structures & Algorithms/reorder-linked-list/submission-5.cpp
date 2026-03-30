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

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second->next != nullptr){
            ListNode* temp = first->next;
            ListNode* tmp = second->next;
            first->next = second;
            second->next = temp;
            first = temp;
            second = tmp;
        }
    }
};
