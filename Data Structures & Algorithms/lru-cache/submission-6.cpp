class LRUCache {
public:
    struct Node{
        Node* next;
        Node* prev;
        int key; 
        int val;
    };
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        this->cap = capacity;

        head = new Node{nullptr,nullptr,0,0};
        tail = new Node{nullptr,nullptr,0,0};

        head->next = tail;
        tail->next = head;
    }
    void remove(Node* node){
       node->prev->next = node->next;
       node->next->prev = node->prev;
    }
    void insertFront(Node* node){
        Node* save = head->next;
        head->next = node;
        node->prev = head;
        node->next = save;
        save->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* n = mp[key];
        remove(n);
        insertFront(n);

        return n->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insertFront(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
            }

            Node* node = new Node{nullptr, nullptr, key, value};
            insertFront(node);
            mp[key] = node;
        }
    }
};
