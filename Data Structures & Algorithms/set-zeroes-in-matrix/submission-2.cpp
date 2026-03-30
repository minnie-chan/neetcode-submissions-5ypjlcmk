class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstColZero =  false;
        bool firstRowZero = false;

        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                firstRowZero = true;
                break;
            }
        }
        
        for(int j = 0; j < cols; j++){
            if(matrix[0][j] == 0){
                firstColZero = true;
                break;
            }
        }
        
        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0; // mark row r
                    matrix[0][c] = 0; // mark column c
                }
            }
        }
        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }

        if (firstColZero == true) {
            for (int c = 0; c < cols; ++c) matrix[0][c] = 0;
        }
        if (firstRowZero == true) {
            for (int r = 0; r < rows; ++r) matrix[r][0] = 0;
        }

    }
};
