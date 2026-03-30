class Solution {
    int movement[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        int rows = grid.size();
        int colums = grid[0].size();

        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < colums; j++){
                if(grid[i][j] == 1){
                    int pirate = 0;
                    dfs(grid,i,j,pirate,rows,colums);
                    ans = max(ans, pirate ) ;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& pirate, int rows, int colums){
        if(i < 0 || j < 0  || 
           i >= rows || j >= colums  || grid[i][j] == 0){
            return;
           }
        pirate++;
        grid[i][j] = 0;
        for(int a = 0; a < 4; a++){
            
            dfs(grid, i + movement[a][0], j + movement[a][1], pirate, rows,colums);
        }
    }
};
