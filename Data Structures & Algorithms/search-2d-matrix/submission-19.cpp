class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Phase 1: binary search rows to find the candidate row
        int left = 0, right = rows - 1;
        int chosenRow = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int rowMin = matrix[mid][0];
            int rowMax = matrix[mid][cols - 1];

            if (target < rowMin) {
                right = mid - 1;
            } else if (target > rowMax) {
                left = mid + 1;
            } else {
                chosenRow = mid; // target could be in this row
                break;
            }
        }

        if (chosenRow == -1) return false; // no row could contain target

        // Phase 2: binary search inside the chosen row
        left = 0;
        right = cols - 1;
        while (left <= right) {
            int midCol = left + (right - left) / 2;
            int val = matrix[chosenRow][midCol];

            if (val == target) return true;
            else if (val < target) left = midCol + 1;
            else right = midCol - 1;
        }

        return false;
    }
};
