class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int size = rows * cols;
        vector<vector<int>> memo(size, vector<int> (size, -1));//idkk im super lost here
        return dfs(0,0,memo,obstacleGrid,rows,cols); 
    }
    int dfs(int r, int c,vector<vector<int>>& memo,vector<vector<int>>& obstacleGrid,
           int rows,int cols){
        if(r >= rows || c >= cols){
            return 0;
        }
        if(obstacleGrid[r][c] == 1){
            return 0;
        }
        if(memo[r][c] != -1){
            return memo[r][c];
        }
        if(r == rows - 1 && c == cols - 1){
            return 1;
        }
         int case_one = dfs(r+1,c,memo,obstacleGrid,rows,cols);
         int case_two  = dfs(r,c+1,memo,obstacleGrid,rows,cols);
         memo[r][c] = case_one + case_two;
         return memo[r][c];
    }
};