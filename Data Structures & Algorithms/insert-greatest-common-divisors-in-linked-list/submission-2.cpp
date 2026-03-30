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
    int gcd(int a, int b){
         while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;

        while(cur != nullptr && cur->next != nullptr){
            int g = gcd(cur->val, cur->next->val);
            ListNode* a = new ListNode(g);
            ListNode* infront = cur->next;
            cur->next = a;
            a->next = infront;
            cur = infront;
        }
        return head;
    }
};