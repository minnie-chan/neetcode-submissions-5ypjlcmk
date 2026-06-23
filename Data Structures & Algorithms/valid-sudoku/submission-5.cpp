class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                char cur = board[i][j];

                if (cur == '.') continue;

                int square = (i / 3) * 3 + (j / 3);

                if (rows[i].contains(cur) ||
                    cols[j].contains(cur) ||
                    squares[square].contains(cur))
                    {
                        return false;
                    }

                rows[i].insert(cur);
                cols[j].insert(cur);
                squares[square].insert(cur);
            }
        }

        return true;
    }
};
