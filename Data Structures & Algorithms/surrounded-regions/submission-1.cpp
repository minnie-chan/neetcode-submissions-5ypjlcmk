class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i = 0; i < r; i++) {
            q.push({i, 0});
            q.push({i, c - 1});
            visited[i][0] = true;
            visited[i][c-1] = true;
        }

        for(int j = 0; j < c; j++) {
            q.push({0, j});
            q.push({r - 1, j});
            visited[0][j] = true;
            visited[r-1][j] = true;
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()){
                    continue;
                }
                if(grid[nx][ny] == 'O' && visited[nx][ny] == false){
                    grid[nx][ny] = 'X';
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                } else if(grid[nx][ny] == 'X' && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    
                }
            }
        }
    }
};
