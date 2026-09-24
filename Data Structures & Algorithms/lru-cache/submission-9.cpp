class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
            Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {};
    };

    int capacity = 0;
    unordered_map<int,Node*> mp;
    Node* dummyHead;
    Node* dummyTail;
    LRUCache(int capacity) {
        this->capacity = capacity;

        dummyTail = new Node(0,0);
        dummyHead = new Node(0,0);

        dummyTail->prev = dummyHead;
        dummyHead->next = dummyTail;
    }
    void remove(Node* node){
        Node* l = node->prev;
        Node* r = node->next;

        l->next = r;
        r->prev = l;
    }
    void addToMRU(Node* node){
        Node* curr = dummyTail;
        Node* a = dummyTail->prev;

        curr->prev = node;
        node->next = curr;

        node->prev = a;
        a->next = node;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
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

        if(mp.size() > capacity){
            Node* lru = dummyHead->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
