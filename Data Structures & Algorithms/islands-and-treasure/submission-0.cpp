class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       int moo[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};  
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
    
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
        }
    }
}       
    while(!q.empty()){
        auto[r,c] = q.front();
            q.pop();

            
            for(int i = 0 ; i < 4; i++){
                int nr = r + moo[i][0];
                int nc = c + moo[i][1];
            
               
               if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue; 
                }
               if (grid[nr][nc] == -1) {
                    continue; 
                }

                    
                    if(grid[nr][nc] == INT_MAX){
                        grid[nr][nc] = grid[r][c] + 1;
                        q.push({nr,nc});
                   }
            }
        }
    }
};
