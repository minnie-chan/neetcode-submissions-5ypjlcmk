class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
    };
    
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node{0, 0, nullptr, nullptr};
        tail = new Node{0, 0, nullptr, nullptr};

        head->next = tail;
        tail->prev = head;
    }
    void remove(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void insertFront(Node* node){
        while(node != nullptr){
            if(node->next == nullptr){

            }
        }
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        remove(node);
        insertFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;

            remove(node);
            insertFront(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
            }

            Node* newNode = new Node{key, value, nullptr, nullptr};
            insertFront(newNode);
            mp[key] = newNode;
        }
    }
};