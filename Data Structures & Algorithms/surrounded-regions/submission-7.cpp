class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                dfs(board, vis, 0, i);
            }

            if (board[r - 1][i] == 'O') {
                dfs(board, vis, r - 1, i);
            }
        }
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                dfs(board, vis, i, 0);
            }

            if (board[i][c - 1] == 'O') {
                dfs(board, vis, i, c - 1);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int x, int y) {
        vis[x][y] = true;

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; k++) {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];
            if (nx < 0 || nx >= board.size() ||
                ny < 0 || ny >= board[0].size()) {
                continue;
            }
            if ( board[nx][ny] == 'O' && vis[nx][ny] == false) {
                 dfs(board, vis, nx, ny);
            }
        }
    }
};
