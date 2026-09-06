class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> f(board.size(), vector<bool>(board[0].size(), false));
        int rows = board.size();
        int cols = board[0].size();

        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') {
                dfs(0, c, f, board);
            }

            if (board[rows - 1][c] == 'O') {
                dfs(rows - 1, c, f, board);
            }
        }

        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                dfs(r, 0, f, board);
            }

            if (board[r][cols - 1] == 'O') {
                dfs(r, cols - 1, f, board);
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O' && !f[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<bool>>& f, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return;
        }
        if (board[r][c] == 'X') {
            return;
        }

        if (f[r][c] == true) {
            return;
        }

        f[r][c] = true;

        dfs(r + 1, c, f, board);
        dfs(r - 1, c, f, board);
        dfs(r, c + 1, f, board);
        dfs(r, c - 1, f, board);
    }
};
