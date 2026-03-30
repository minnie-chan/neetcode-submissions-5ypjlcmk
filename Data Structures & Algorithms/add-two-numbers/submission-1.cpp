class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* ans = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;  // ternary: if l1 exists use its val, otherwise 0
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int total = v1 + v2 + carry;
            int digit = total % 10;    // the digit to store in this node
            carry = total / 10;        // update carry for next iteration

            ans->next = new ListNode(digit);  // create and attach node
            ans = ans->next;                  // advance ans

            if (l1 != nullptr) l1 = l1->next;  // only advance if not null
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy.next;
    }
};
