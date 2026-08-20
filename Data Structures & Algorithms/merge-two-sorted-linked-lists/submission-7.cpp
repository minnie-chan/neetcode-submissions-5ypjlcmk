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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val >= l2->val){//if we odnt do curr->next then if we try to do curr = l1  then woudlnt curr be stting it liek the node and value at null becuase curr is i gues behind dummy ?
                curr->next = l2;//this gives us the node and value at l2
                l2 = l2->next;
            } else if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if(l1 != nullptr){
            curr->next = l1;
            l1 = l1->next;
        } else if(l2 != nullptr){
            curr->next = l2;
            l2 = l2->next;
        }
        
        return dummy.next;
    }
};
