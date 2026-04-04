class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
        int track;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    track = dfs(grid,i,j);
                    ans = max(ans, track);
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return 0;
        }
        if(grid[r][c] == 0 ){
            return 0;
        }
        
        grid[r][c] = 0;
        

        return 1 + 
        dfs(grid,r+1,c) +
        dfs(grid,r-1,c) +
        dfs(grid,r,c+1) +
        dfs(grid,r,c-1);
    }
};
