class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0].empty() || matrix.empty()){
            return false;//not sure about this  
        }
        int left = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();
        int chosenrow = 0;
        int right = rows - 1;
        while(left <= right){
            int middle = left + (right - left) / 2;
            
            int rowmin = matrix[middle][0];
            int rowmax = matrix[middle][cols - 1];
            
            if(target  < rowmin){
                right = middle - 1;
            } else if(target > rowmax){
                left = middle + 1;
            } else {
                chosenrow = middle;
            }
            left = 0;
            right = cols - 1;
            while(left <= right){
                int midCol = left + (right - left) /2;
                if(matrix[chosenrow][midCol] > target){
                    right = middle -1;
                } else if(matrix[chosenrow][midCol] < target){
                    left = middle + 1;
                } else if(matrix[chosenrow][midCol] == target){
                    return true;
                }
            }
        }
        return false;
    }
};
