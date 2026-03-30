class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        // Pass 1: create copies of all nodes
        Node* cur = head;
        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Pass 2: wire next and random pointers
        cur = head;
        while (cur != nullptr) {

            mp[cur]->next = (cur->next ? mp[cur->next] : nullptr);
            mp[cur]->random = (cur->random ? mp[cur->random] : nullptr);
            cur = cur->next;
        }

        return mp[head];
    }
};
