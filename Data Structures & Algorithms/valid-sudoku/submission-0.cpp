class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        char val;
    for(int r = 0; r <= 8; r++){
       for(int c = 0; c <= 8; c++){
        val = board[r][c];
        if(val == '.'){
            continue;
        }
        if(rows[r].count(val)){
            return false;
        }
        if(cols[c].count(val)){
            return false;
        }
        int boxIndex = (r/3) * 3 + (c / 3);
        if(boxes[boxIndex].count(val)){
            return false;
        }
        rows[r].insert(val);
        cols[c].insert(val);
        boxes[boxIndex].insert(val);

       }
    }
    return true;
    }
};
