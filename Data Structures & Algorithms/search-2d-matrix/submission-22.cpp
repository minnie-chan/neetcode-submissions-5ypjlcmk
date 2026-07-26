class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(matrix[mid][0] > target){
                r = mid - 1;
            } else if(matrix[mid][0] < target){
                l = mid + 1;
            } else {
                return true;
            }
        }
        
        if(r == -1){
            return false;
        }
        int row = r;
        l = 0;
        int right = matrix[row].size() - 1;

        while(l <= right){
            int middle = l + (right - l) / 2;
            if(matrix[row][middle] > target){
                right = middle - 1;
            } else if(matrix[row][middle] < target){
                l = middle + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
