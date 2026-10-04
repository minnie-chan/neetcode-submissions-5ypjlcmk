class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dirs[4][2] =  {{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>> q;
        int a = 0;
                    int fresh = 0;
        for(int i = 0 ; i < r;i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }   
        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for(int i = 0 ;i < size;i++){
                auto [x,y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + dirs[j][0];
                    int ny = y + dirs[j][1];

                    if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                        continue;
                    }

                    if(grid[nx][ny] == 0){
                        continue;
                    }

                    if(grid[nx][ny] == 1){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        fresh --;
                    }
                }         
            }

            a++;
        }
                    if (fresh > 0) {
                return -1;
            }
        return a;
    }
};
