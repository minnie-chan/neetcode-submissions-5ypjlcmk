class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int track = 0;
        int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
            }
        }
        while(!qu.empty()){
            auto[i,j] = qu.front();
            qu.pop();

            for(int a = 0; a < 4; a++){
                int x = i + dir[a][0];
                int y = j + dir[a][1];

                if(x < 0 || x >= rows || y < 0 || y >= cols){
                    continue;
                }
                if(grid[x][y] == 0){
                    continue;
                }
                if(grid[x][y] == 1){
                    qu.push({x,y});
                    track ++;
                    grid[x][y] = 2;
                } else if(grid[x][y] == 2){
                    continue;
                }
            }
            
        }
        return track -1;
    }
};
