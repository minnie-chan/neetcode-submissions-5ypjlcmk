class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int total = m * n;
        int r = 0, c = 0, dir = 0;

        int dr[4] = {0, 1, 0, -1}; // right, down, left, up
        int dc[4] = {1, 0, -1, 0};

        for (int i = 0; i < total; i++) {
            ans.push_back(matrix[r][c]);
            vis[r][c] = true;

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }

            r = nr;
            c = nc;
        }

        return ans;
    }
};
