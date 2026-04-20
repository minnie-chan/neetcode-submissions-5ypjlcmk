class PrefixTree {
public:

    struct Node {
        unordered_map<char, Node*> mp;
        bool isEnd = false;
    };
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for(char c: word){
            
            if(node->mp.find(c) == node->mp.end()){
                node->mp[c] = new Node();
            }
            node = node->mp[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            if(node->mp.find(c) == node->mp.end()){
                return false;
            }
            // woudl i have to move the map here?
            node = node->mp[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
                Node* node = root;

        for (char c : word) {
            if(node->mp.find(c) == node->mp.end()){
                return false;
            }
            // woudl i have to move the map here?
            node = node->mp[c];
        }
        return node->isEnd;
    }
};
