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
        Node* move = head;
        map<Node*,Node*> mp;

        while(move != nullptr){
            mp[move] = new Node(move->val);
            move = move->next;
        }

        
        move = head;
        while(move != nullptr){
            mp[move]->next = (move->next ? mp[move->next] : nullptr); 
            mp[move]->random = (move->random ? mp[move->random] : nullptr);
            move = move->next;
        }
        return mp[head];
    }
};
