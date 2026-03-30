class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int best  = 0;
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return dfs(0,0,memo,rows,cols,grid,best);
    }
    int dfs(int r, int c, vector<vector<int>>& memo, int rows,
            int cols,vector<vector<int>>& grid, int best ){
        if(r >= rows || c >= cols){
           return INT_MAX / 2; // this one really cool trick 
        }
        if(r == rows-1 && c == cols-1){
            return grid[r][c];
        }
        if(memo[r][c] != -1){
            return memo[r][c];
        }
       


        int a = dfs(r + 1,c, memo, rows, cols, grid,best);
        int b = dfs(r,c + 1, memo, rows, cols, grid,best);
        best = grid[r][c] + min(a,b);
        memo[r][c] = best;// this one 
        return memo[r][c]; // this one and 
    }
};