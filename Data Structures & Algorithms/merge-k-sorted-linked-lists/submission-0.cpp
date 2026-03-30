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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* push = &dummy;
        vector<int> vec;
        for(ListNode* lit: lists){
            while(lit != nullptr){
                vec.push_back(lit->val);
                lit = lit->next;
            }
        }
        sort(vec.begin(), vec.end());

        for(int i = 0; i < vec.size();i++){
            push->next = new ListNode(vec[i]);  
            push = push->next;
        }
        return dummy.next;
    }
};
