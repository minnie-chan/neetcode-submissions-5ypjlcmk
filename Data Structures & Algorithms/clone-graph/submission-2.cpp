/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        map<Node*,Node*> mp;
        return dfs(node,mp);
    }
    Node* dfs(Node* node, map<Node*,Node*>& mp){
        if(mp.find(node) != mp.end()){
            return mp[node];
        }

        Node* new_Neighbor = new Node(node->val);
        mp[node] = new_Neighbor;

        for(Node* size : node->neighbors){
            Node* why = dfs(size,mp);
            why->neighbors.push_back(new_Neighbor);
        }
        return new_Neighbor;
    }
};
