class PrefixTree {
public:

    struct Node {
        unordered_map<char,Node*> mp;
        bool isEnd = false;
    };
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(char size : word){
            if(node->mp.find(size) == node->mp.end()){
                node->mp[size] = new Node();
            }
            node = node->mp[size];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;

        for(char a : word){
            if(node->mp.find(a) == node->mp.end()){
                return false;
            }
            node = node->mp[a];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
                Node* node = root;

        for(char a : prefix){
            if(node->mp.find(a) == node->mp.end()){
                return false;
            }
            node = node->mp[a];
        }
        return true;
    }
};
