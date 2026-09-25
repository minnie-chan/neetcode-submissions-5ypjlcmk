class LRUCache {
   public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, Node*> mp;
    int capacity;
    Node* dummyHead;
    Node* dummyTail;
    LRUCache(int capacity) {
        this->capacity = capacity;

        dummyTail = new Node(0, 0);
        dummyHead = new Node(0, 0);

        dummyTail->prev = dummyHead;
        dummyHead->next = dummyTail;
    }
    void remove(Node* node) {
        Node* l = node->prev;
        Node* r = node->next;

        l->next = r;
        r->prev = l;
    }
    void mru(Node* node) {
        Node* hold = dummyTail->prev;

        dummyTail->prev = node;
        node->next = dummyTail;
        node->prev = hold;
        hold->next = node;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* a = mp[key];
        remove(a);
        mru(a);
        return  a->val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* a = mp[key];
            a->val = value;
            remove(a);
            mru(a);
            return;
        }

        Node* node = new Node(key,value);
        mp[key] = node;
        mru(node);

        if (mp.size() > capacity){
            Node* DELETE = dummyHead->next;

            remove(DELETE);
            mp.erase(DELETE->key);
            delete DELETE;
        }
    }
};
