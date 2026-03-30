class Solution {
public:
    void reorderList(ListNode* head) {
        // Edge cases: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // --------------------------------------------------
        // 1) Find the middle of the list
        // --------------------------------------------------
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;    // move 2 steps
        }

        // After this loop:
        // slow is at the middle

        // --------------------------------------------------
        // 2) Reverse the second half of the list
        // --------------------------------------------------
        ListNode* second = slow->next;  // start of second half
        slow->next = nullptr;           // CUT the list (important)

        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }

        // After reversing:
        // prev is the head of the reversed second half
        second = prev;

        // --------------------------------------------------
        // 3) Merge the two halves (zip them together)
        // --------------------------------------------------
        ListNode* first = head;

        while (second != nullptr) {
            // Save next pointers
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            // Weave nodes together
            first->next = second;
            second->next = tmp1;

            // Move pointers forward
            first = tmp1;
            second = tmp2;
        }
    }
};
