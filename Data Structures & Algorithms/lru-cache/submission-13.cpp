class LRUCache {
   public:
    struct Node {
        int key;
        int val;

        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    void replace(Node* curr) {
        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void mru(Node* node) {
        Node* hold = tail->prev;

        tail->prev = node;
        node->next = tail;
        node->prev = hold;
        hold->next = node;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* curr = mp[key];
        replace(curr);
        mru(curr);
        // move curr to front

        return curr->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            curr->val = value;
            replace(curr);
            mru(curr);
            return;
        }
        
        Node* node = new Node(key,value);
        mp[key] = node;
        mru(node);
        if(mp.size() > capacity){
            Node* curr = head->next;

            replace(curr);
            mp.erase(curr->key);
            delete curr;
        }
    }
};
