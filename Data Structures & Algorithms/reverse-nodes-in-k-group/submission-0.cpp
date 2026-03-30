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
        ListNode* newHead = rv(head,k);

        head->next = reverseKGroup(curr, k);

        return newHead;
    }
    ListNode* rv(ListNode* curr, int k){
        ListNode* prev = nullptr;
        
        while(k--){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            
        }
        return prev;
    }
};
