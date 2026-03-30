/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* travel = head;

        while(travel != nullptr){
            mp[travel] = new Node(travel->val);
            travel = travel->next;
        }

        travel = head;
        while(travel != nullptr){
            mp[travel]->next = (travel->next ? mp[travel->next]:nullptr);
            mp[travel]->random = (travel->random ? mp[travel->random] : nullptr);
            travel = travel->next;
        }
        return mp[head];
    }
};
