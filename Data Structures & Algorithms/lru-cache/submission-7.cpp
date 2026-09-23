class LRUCache {
   public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    int capacity;
    unordered_map<int, Node*> mp;
    Node* dummyHead;
    Node* dummyTail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        dummyHead = new Node(0, 0);
        dummyTail = new Node(0, 0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;


    }
    void remove(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }
    void addToMRU(Node* node) {
        Node* oldLast = dummyTail->prev;

        oldLast->next = node;
        node->prev = oldLast;

        node->next = dummyTail;
        dummyTail->prev = node;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        addToMRU(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;
            remove(node);
            addToMRU(node);

            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        addToMRU(node);
        if (mp.size() > capacity){
            Node* lru = dummyHead->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
