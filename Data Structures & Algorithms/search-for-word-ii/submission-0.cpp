class Solution {
public:
    struct Node {
        unordered_map<char, Node*> mp;
        bool isEnd = false;
        string word = "";
    };

    void insert(string& word, Node* root) {
        Node* node = root;

        for (char c : word) {
            if (node->mp.find(c) == node->mp.end()) {
                node->mp[c] = new Node();
            }
            node = node->mp[c];
        }

        node->isEnd = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node, vector<string>& ans) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        if (node->mp.find(ch) == node->mp.end()) {
            return;
        }

        node = node->mp[ch];

        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node, ans);
        dfs(board, r - 1, c, node, ans);
        dfs(board, r, c + 1, node, ans);
        dfs(board, r, c - 1, node, ans);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        vector<string> ans;

        for (string& word : words) {
            insert(word, root);
        }

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root, ans);
            }
        }

        return ans;
    }
};