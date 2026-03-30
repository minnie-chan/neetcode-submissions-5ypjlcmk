class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int a = grid.size();
        int b = grid[0].size(); 
        if(grid[0][0] == 1){
            return 0;
        } else {
            grid[0][0] = 1;
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int up = 0;
                int left = 0;
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    continue;
                } 
                if(i > 0){
                   up = grid[i-1][j];
                }
                if(j > 0){
                   left = grid[i][j-1];
                }
                grid[i][j] = up + left;
            }
            
        }
        return grid[a-1][b-1];
    }
};