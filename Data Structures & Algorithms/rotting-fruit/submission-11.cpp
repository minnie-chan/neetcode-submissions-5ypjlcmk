class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto hold = q.front();
            q.pop();

            int a = hold.first;
            int b = hold.second;

            for(int i = 0; i < 4; i++){

                int nx = a + x[i];
                int ny = b + y[i];

                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()){
                    continue;
                }
                if(grid[nx][ny] == 0){
                    continue;
                }
                if(grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                    ans ++;
                }
            }
        }
        return ans;
    }
};
