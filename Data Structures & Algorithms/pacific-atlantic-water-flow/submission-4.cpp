class Solution {
   public:
           int dir[4][2] = {{1,0},
                         {-1,0},
                         {0,1},
                         {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> ans;
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);
        }

        for(int r = 0; r < rows;r++){
            dfs(r,0,heights,pacific);
        }

        for (int c = 0; c < cols; c++) {
            dfs(rows - 1, c, heights, atlantic);
        }

        for(int r = 0; r < rows;r++){
            dfs(r,cols - 1,heights,atlantic);
        }
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < cols;j++){
                if(pacific[i][j] == true && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nx = r + dir[i][0];
            int ny = c + dir[i][1];

            if (nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size()) {
                continue;
            }

            if (visited[nx][ny] == true) {
                continue;
            }

            if (heights[nx][ny] >= heights[r][c]) {
                dfs(nx, ny, heights, visited);
            }
        }
    }
};
