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
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> mp;

        // Pass 1: create all nodes
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Pass 2: connect next/random using the map
        cur = head;
        while (cur) {
            Node* copy = mp[cur];
            copy->next = (cur->next ? mp[cur->next] : nullptr);
            copy->random = (cur->random ? mp[cur->random] : nullptr);
            cur = cur->next;
        }

        return mp[head];
    }
};
