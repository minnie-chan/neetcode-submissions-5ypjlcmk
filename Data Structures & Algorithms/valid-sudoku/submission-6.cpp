class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                char cur = board[r][c];

                int box = (r / 3) * 3 + (c / 3);

                if (rows[r].find(cur) != rows[r].end() || cols[c].find(cur) != cols[c].end() ||
                    boxes[box].find(cur) != boxes[box].end()) {
                        return false;
                }

                rows[r].insert(cur);
                cols[c].insert(cur);
                boxes[box].insert(cur);
            }
        }

        return true;
    }
};
