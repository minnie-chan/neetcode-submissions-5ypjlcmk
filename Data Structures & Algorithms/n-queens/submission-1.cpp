class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        
        vector<int> queens(n);
        backtrack(0, n, queens, result);
        return result;
        
    }
    bool isSafe(int row, int col, vector<int>& queens){
        for (int i = 0; i < row; i++) {
        if (queens[i] == col) return false;  // same column
        if (abs(i - row) == abs(queens[i] - col)) return false;  // diagonal
    }
        return true;
    }
    void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& result) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int r = 0; r < n; r++) {
                board[r][queens[r]] = 'Q';
            }
            result.push_back(board);
            return;
        }   

        for(int col = 0; col < n; col++){
            if(isSafe(row, col, queens)){
                queens[row] = col;
                backtrack(row + 1, n, queens, result);
            }
        }
    }
};
