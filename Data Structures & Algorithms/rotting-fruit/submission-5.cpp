class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int time = -1;
        queue<pair<int,int>> qu;
        int track = 0;
        int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                } else if(grid[i][j] == 1){
                    track++;
                }
            }
        }

        while(!qu.empty()){
            int size = qu.size();
            time++;
            for(int a = 0;a < size;a++) {
                auto [i,j] = qu.front();
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
                    grid[x][y] = 2;
                     track --;
                } else if(grid[x][y] == 2){
                   
                    continue;
                   
                }
            }
            
             if(track <= 0) break;
            }
            
        }
        
        if(track > 0){
            return -1;
        } 
        return time;
    }
};

