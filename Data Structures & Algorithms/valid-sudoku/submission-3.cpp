class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i = 0; i < board.size();i++){
            unordered_set<char> seen;
            unordered_set<char> s;
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j] != '.'){
                    if (seen.find(board[i][j]) != seen.end()) {
                        return false;
                    } 
                    seen.insert(board[i][j]);                    
                }

                if(board[j][i] != '.'){
                    if (s.find(board[j][i]) != s.end()) {
                        return false;
                    }
                    s.insert(board[j][i]); 
                }         
            }
        }
        unordered_set<char> boxSeen;

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> boxSeen;

                for (int r = boxRow; r < boxRow + 3; r++) {
                    for (int c = boxCol; c < boxCol + 3; c++) {
                        if (board[r][c] != '.') {
                            if (boxSeen.find(board[r][c]) != boxSeen.end()) {
                                return false;
                            }
                            boxSeen.insert(board[r][c]);
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
