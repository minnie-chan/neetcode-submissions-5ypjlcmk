class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l <= r) {
            int middle = l + (r - l) / 2;
            if (matrix[middle][0] == target) {
                return true;
            } else if (matrix[middle][0] < target) {
                l = middle + 1;
            } else if (matrix[middle][0] > target) {
                r = middle - 1;
            }
        }

        if (r == -1) {
            return false;
        }
        l = 0;
        int nr = matrix[r].size();
        int b = matrix[r].size() - 1;
        while (l <= b) {
            int middle = l + (b - l) / 2;

            if (matrix[r][middle] > target) {
                b = middle - 1;
            } else if (matrix[r][middle] < target) {
                l = middle + 1;
            } else if (matrix[r][middle] == target) {
                return true;
            }
        }
        return false;
    }
};
