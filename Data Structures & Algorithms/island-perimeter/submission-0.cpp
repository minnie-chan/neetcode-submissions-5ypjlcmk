class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perim = 0;
        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // down, up, right, left

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;

                for (auto &d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    // treat off-grid as water
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0)
                        ++perim;
                }
            }
        }
        return perim;
    }
};
