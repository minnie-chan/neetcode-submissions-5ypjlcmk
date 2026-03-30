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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevLeft = &dummy;

        for(int i = 1; i < left; i++){
            prevLeft = prevLeft->next;
        }
        ListNode* leftNode = prevLeft->next;
        ListNode* curr = leftNode;
        int sum = right - left + 1;
        int i = 0;
        ListNode* prev = nullptr;
        while(i < sum){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

            i++;
        }
        prevLeft->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }
};