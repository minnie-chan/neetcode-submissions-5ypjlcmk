class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;


        while( l <= r){
            int middle = l + (r - l) / 2;

            if(matrix[middle][0] > target){
                r = middle - 1;
            } else if(matrix[middle][0] < target){
                l = middle + 1;
            } else {
                return true;
            }
        }

        if(r == -1){
            return false;
        }
        int row = r;
        int a = matrix[r].size() -1;
        l = 0;
        while(l <= a){
            int m = l + (a - l) / 2;
            if(matrix[r][m] > target){
                a = m - 1;
            } else if(matrix[r][m] < target){
                l = m + 1;
            } else if(matrix[r][m] == target){
                return true;
            }
        }
        return false;
    }
};
