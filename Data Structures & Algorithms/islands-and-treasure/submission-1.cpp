class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return;
        queue<pair<int,int>> q;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1}; 
        int r = grid.size();
        int c = grid[0].size();
        const int INF = 2147483647;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto qu = q.front();
            q.pop();

            int row = qu.first;
            int col = qu.second;

            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr < 0 || nc < 0 || nr >= r || nc >= c){
                    continue; 
                }
                if(grid[nr][nc] == INF){
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
