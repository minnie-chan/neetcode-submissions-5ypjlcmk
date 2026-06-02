class Solution {
public:
    vector<vector<int>> memo;

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // create memo table
        memo = vector<vector<int>>(rows, vector<int>(cols, -1));

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                answer = max(answer, dfs(matrix, row, col));
            }
        }

        return answer;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col) {

        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        int longestPath = 1;

        // down
        if (row + 1 < matrix.size() &&
            matrix[row + 1][col] > matrix[row][col]) {

            longestPath = max(
                longestPath,
                1 + dfs(matrix, row + 1, col)
            );
        }

        // up
        if (row - 1 >= 0 &&
            matrix[row - 1][col] > matrix[row][col]) {

            longestPath = max(
                longestPath,
                1 + dfs(matrix, row - 1, col)
            );
        }

        // right
        if (col + 1 < matrix[0].size() &&
            matrix[row][col + 1] > matrix[row][col]) {

            longestPath = max(
                longestPath,
                1 + dfs(matrix, row, col + 1)
            );
        }

        // left
        if (col - 1 >= 0 &&
            matrix[row][col - 1] > matrix[row][col]) {

            longestPath = max(
                longestPath,
                1 + dfs(matrix, row, col - 1)
            );
        }

        memo[row][col] = longestPath;
        return longestPath;
    }
};