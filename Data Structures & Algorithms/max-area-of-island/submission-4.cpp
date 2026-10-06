class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int amount = 0;
        int track = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                if(grid[i][j] == 1){
                    
                    dfs(i,j,grid,track);
                }
                amount = max(amount,track);
                track = 0;
            }
        }
        return amount;
    }
    void dfs(int r, int c, vector<vector<int>>& grid,int& track){

        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return;
        }

        if(grid[r][c] == 0){
            return;
        }


        if(grid[r][c] == 1){
            grid[r][c] = 0;
            track++;
            dfs(r+1,c,grid,track);
            dfs(r-1,c,grid,track);
            dfs(r,c+1,grid,track);
            dfs(r,c-1,grid,track);
        }
    }
};
