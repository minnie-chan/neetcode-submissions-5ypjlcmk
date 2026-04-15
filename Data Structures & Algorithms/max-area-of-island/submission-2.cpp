class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c,false));

        int count = 0;

        for (int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                if (!visited[i][j]) {
                    int a = dfs(grid, visited, i, j);
                    count =  max(count, a);
                }
            }
        }

        return count;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,int r,int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return 0;
        }
        if(grid[r][c] == 0 ){
            return 0;
        }
        if(visited[r][c] == true){
            return 0;
        }
        
            visited[r][c] = true;
        return 1+
        dfs(grid,visited,r+1,c)+
        dfs(grid,visited,r-1,c)+
        dfs(grid,visited,r,c+1)+
        dfs(grid,visited,r,c-1);
        
    }
    
};
