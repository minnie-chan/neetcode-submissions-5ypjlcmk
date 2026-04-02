class WordDictionary {
public:
    struct Node{
        unordered_map<char, Node*> mp;
        bool isEnd = false;
    };
    Node* root;
    WordDictionary() {
        root = new Node();
        
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char w : word){
            if(node->mp.find(w) == node->mp.end()){
                node->mp[w] = new Node();
            }
            node = node->mp[w];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, Node* node) {
        if (i == word.size()) {
            return node->isEnd;
        }

        char c = word[i];

        if (c == '.') {
            // try all children
            for (auto& pair : node->mp) {
                if (dfs(word, i + 1, pair.second)) {
                    return true;
                }
            }
            return false;
        } else {
            // normal case
            if (node->mp.find(c) == node->mp.end()) {
                return false;
            }

            // ??? what goes here?
            return dfs(word, i + 1, node->mp[c]);
        }
    }
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
};
