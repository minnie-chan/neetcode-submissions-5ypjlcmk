class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix[0].size() - 1;

        while(left <= right){
            int middle = left + (right - left) / 2;
            if(matrix[0][middle] > target){
                right = middle - 1;
            } else if(matrix[0][middle] < target){
                left = middle + 1;
            } else if(matrix[0][middle] == target){
                return true;
            }
        }
        return false;
    }
};
