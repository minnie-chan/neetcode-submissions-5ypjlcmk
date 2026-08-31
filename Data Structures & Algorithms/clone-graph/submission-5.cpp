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

        // Empty graph
        if (node == nullptr) {
            return nullptr;
        }

        // KEY   = original node
        // VALUE = cloned version of that node
        unordered_map<Node*, Node*> mp;

        // dfs(node) returns the cloned version of node
        return dfs(node, mp);
    }


    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {

        // If we've already cloned this node,
        // DON'T create another copy.
        //
        // This is also what prevents infinite recursion
        // when the graph has cycles.
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }


        // Clone the CURRENT node.
        //
        // original node -> copied node
        mp[node] = new Node(node->val);


        // Look through every ORIGINAL neighbor
        // connected to the current node.
        for (Node* nei : node->neighbors) {

            // dfs(nei) gives us the CLONED version
            // of this neighbor.
            Node* clonedNeighbor = dfs(nei, mp);


            // mp[node] = cloned current node
            //
            // Add the CLONED neighbor to the
            // CLONED current node's neighbors.
            mp[node]->neighbors.push_back(clonedNeighbor);
        }


        // Return the cloned version of the current node.
        return mp[node];
    }
};