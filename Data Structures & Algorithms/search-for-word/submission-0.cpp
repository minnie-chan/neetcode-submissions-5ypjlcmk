class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        // Base case: matched full word
        if (index == word.length()) {
            return true;
        }

        // Bounds check + mismatch check
        if (r < 0 || c < 0 || 
            r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Restore
        board[r][c] = temp;

        return found;
    }
};