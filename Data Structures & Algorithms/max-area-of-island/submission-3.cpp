class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                        int b = 0;
                if (grid[i][j] == 1) {

                   dfs(i, j,grid,b);
                }
                ans = max(ans, b);
            }
        }
        return ans;
    }
    void dfs(int r, int c, vector<vector<int>>& grid,int&  b) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == 0) {
            return;
        }

        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            dfs(r + 1, c, grid,b);
            dfs(r - 1, c, grid,b);
            dfs(r, c + 1, grid,b);
            dfs(r, c - 1, grid,b);
            b++;
        }
    }
};
