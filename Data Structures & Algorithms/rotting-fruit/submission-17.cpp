class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int levels = 0;
        int a = 0;
        queue<pair<int,int>> q;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++) {
                if(grid[i][j] == 1){
                    a++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while (!q.empty() && a > 0) {
            int size = q.size();

            for(int i = 0; i < size;i++){
                auto [x,y] = q.front();
                q.pop();

                for(int j = 0; j < 4;j++){
                    int nx = x + dirs[j][0];
                    int ny = y + dirs[j][1];

                    if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                        continue;
                    }

                    if(grid[nx][ny] == 1){
                        a--;
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        
                    }
                }
                 
            }
            levels++;
        }
        if(a > 0){
            return -1;
        }
        return levels;
    }
};
