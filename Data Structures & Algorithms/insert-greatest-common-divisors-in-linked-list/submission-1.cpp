class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return head;

        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            int g = gcd(cur->val, cur->next->val);

            ListNode* nxt = cur->next;
            ListNode* mid = new ListNode(g);

            cur->next = mid;
            mid->next = nxt;

            cur = nxt;
        }
        return head;
    }
};
