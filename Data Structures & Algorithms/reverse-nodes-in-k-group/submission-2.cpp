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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for(int i = 0; i < k; i++){
            if(curr == nullptr){
                return head;
            }
            curr = curr->next;
        }
        
        ListNode* reversed = rev(head,k);
        head->next = reverseKGroup(curr,k);
        return reversed;

    }
    ListNode* rev(ListNode* head, int k){
        ListNode* prev = nullptr;

        while(k != 0){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            k--;
        }
        return prev;
    }
};
