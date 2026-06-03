class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size() + 1, vector<int>(matrix[0].size() + 1, - 1));
        vector<pair<int,int>> dir = {{1,0},
                                     {-1,0},
                                     {0,1},
                                     {0,-1}};

        int ans = 1;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, dfs(i,j,matrix,memo,dir));
            }
        }
        return ans;
    }
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& memo, vector<pair<int,int>>& dir){
        if(memo[r][c] != -1){
            return memo[r][c];
        }
        int best =  1;
        for(auto& [x,y] : dir){
            int nx = r + x;
            int ny = c + y;

            if(nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()){
                continue;
            }
            if(matrix[nx][ny] > matrix[r][c]){
                best = max(best, 1 + dfs(nx,ny,matrix,memo,dir));
            }
        }
        memo[r][c] = best;
        return best;
    }
};
