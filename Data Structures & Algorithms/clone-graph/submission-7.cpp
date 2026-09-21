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

        unordered_map<Node*,Node*> mp;

        Node* curr = node;
        if(curr == nullptr){
            return nullptr;
        }
        return dfs(mp,curr);
       
    }
    Node* dfs(unordered_map<Node*,Node*>& mp,Node* curr ){
        if(mp.find(curr) != mp.end()){
            return mp[curr];
        }
        Node* copy = new Node(curr->val);
        mp[curr] = copy;

        for(auto& nei : curr->neighbors){
            copy->neighbors.push_back(dfs(mp,nei));
        }
        
        return copy;
    }
};
