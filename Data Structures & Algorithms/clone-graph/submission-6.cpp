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
    if (node == nullptr) {
        return nullptr;
    }

    unordered_map<Node*, Node*> mp;

    return dfs(node, mp);

    }
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp){
        Node* curr = node;
        if(mp.find(curr) != mp.end()){
            return mp[curr];
        }

        mp[curr] = new Node(curr->val);

        for(auto& nei : curr->neighbors){
            mp[curr]->neighbors.push_back(dfs(nei, mp));
        }
        return mp[curr];  
    }
};
