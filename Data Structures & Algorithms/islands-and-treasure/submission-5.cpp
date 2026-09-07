class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*  Why put ALL treasures in first? becuse if we do can jsut trvael throgh them and then get
           thei distance like that Why only enter INF cells? becuase thats  valid land cell to
           travere throguh Why current distance + 1? it basically means how many steps from the
           treasue did it take to reah from a land cell
        */
        queue<pair<int, int>> qu;
        int r = grid.size();
        int c = grid[0].size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    qu.push({i, j});
                }
            }
        }
        const int INF = INT_MAX;
        while(!qu.empty()){
            auto [x,y] = qu.front();
            qu.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()){
                    continue;
                }

                if(grid[nx][ny] == INF){
                    grid[nx][ny] = grid[x][y] +  1;
                    qu.push({nx, ny});
                }
                
            }
        }
    }
};
