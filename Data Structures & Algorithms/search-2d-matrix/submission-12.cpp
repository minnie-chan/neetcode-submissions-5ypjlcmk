class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i;
        for(i = 0;i < m;i++) {
            if(target <= matrix[i][n-1] ) {
                break;
            }
        }
            if(i == m){return false;}
        return binarySearch(matrix[i], target);
    }
     

    bool binarySearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() -1;

        while(left <= right){
            int middle = left + (right - left) / 2;
            
             if(vec[middle] < target){
                left = middle + 1;
            } else if(vec[middle] > target) {
                right = middle -1;
            } else if(vec[middle] == target){
                return true;
            } 
       
    } 
        return false;
    }
};
