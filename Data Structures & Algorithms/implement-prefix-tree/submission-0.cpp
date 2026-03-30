class PrefixTree {
   private:
    struct Node {
    Node* children[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
    };
    Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
         Node* cur = root;
    for (char c : word) {
        int index = c - 'a';
        if (cur->children[index] == nullptr)
            cur->children[index] = new Node();
        cur = cur->children[index];
    }
    cur->isEnd = true;
    }
    
    bool search(string word) {
         Node* cur = root;
    for (char c : word) {
        int index = c - 'a';
        if (cur->children[index] == nullptr)
            return false;
        cur = cur->children[index];
    }
    return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
    for (char c : prefix) {
        int index = c - 'a';
        if (cur->children[index] == nullptr)
            return false;
        cur = cur->children[index];
    }
    return true;
    }
};
