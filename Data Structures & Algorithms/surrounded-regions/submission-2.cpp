class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i = 0; i < r; i++) {
            if(grid[i][0] == 'O' && visited[i][0] == false){
                visited[i][0] = true;
                q.push({i, 0});
            }
            if(grid[i][c-1] == 'O' && visited[i][c-1] == false){
                visited[i][c-1] = true;
                q.push({i, c-1});
            }
        }

        for(int j = 0; j < c; j++) {
            if(grid[0][j] == 'O' && visited[0][j] == false){
                visited[0][j] = true;
                q.push({0, j});
            }
            if(grid[r-1][j] == 'O' && visited[r-1][j] == false){
                visited[r-1][j] = true;
                q.push({r - 1, j});
            }
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
                    
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                } 
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 'O' && !visited[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
