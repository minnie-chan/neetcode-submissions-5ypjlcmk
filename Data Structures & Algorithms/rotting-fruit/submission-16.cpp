class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int levels = 0;
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int a = 0; a < size; a++) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];

                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
                        continue;
                    }
                    if (grid[nx][ny] == 0) {
                        continue;
                    }

                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            levels++;
        }
        if (fresh > 0) {
            return -1;
        }

        return levels;
    }
};
