class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(
            matrix.size(),
            vector<int>(matrix[0].size(), -1)
        );

        vector<pair<int,int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(i, j, memo, dirs, matrix));
            }
        }

        return ans;
    }

    int dfs(
        int r,
        int c,
        vector<vector<int>>& memo,
        vector<pair<int,int>>& dirs,
        vector<vector<int>>& matrix
    ) {
        if (memo[r][c] != -1) {
            return memo[r][c];
        }

        int best = 1;

        for (auto& [dx, dy] : dirs) {
            int nX = r + dx;
            int nY = c + dy;

            if (nX < 0 || nX >= matrix.size() ||
                nY < 0 || nY >= matrix[0].size()) {
                continue;
            }

            if (matrix[nX][nY] > matrix[r][c]) {
                best = max(
                    best,
                    1 + dfs(nX, nY, memo, dirs, matrix)
                );
            }
        }

        memo[r][c] = best;
        return best;
    }
};