class PrefixTree {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool isEnd = false;
    };
    Node* root;

    PrefixTree() {  
        root = new Node();
    }


    void insert(string word) {
        Node* curr = root;
        for(auto& c : word){
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        
        for(auto& w: word){
            if(curr->children.find(w) == curr->children.end()){
                return false;
            }
            curr = curr->children[w];
        }
        
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(auto& p: prefix){

            if(curr->children.find(p) == curr->children.end()){
                return false;
            }
            curr = curr->children[p];
        }

        return true;
    }
};
