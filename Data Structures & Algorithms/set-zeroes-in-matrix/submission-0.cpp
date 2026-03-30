class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> rowzero(rows, false);
        vector<bool> colzero(cols, false);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    rowzero[i] = true;
                    colzero[j] = true;
                }
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rowzero[i] == true || colzero[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }
        

    
    }
};
