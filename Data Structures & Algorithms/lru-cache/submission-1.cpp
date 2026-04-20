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