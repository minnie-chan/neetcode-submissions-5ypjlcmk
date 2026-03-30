class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(0,0,m,n,memo);
    }
    int dfs(int r, int c, int m, int n, vector<vector<int>>& memo ){
        if(r >= m || r < 0 || c >= n || c < 0){
            return 0;
        }
        if(memo[r][c] != -1){
            return memo[r][c];
        }
        if(r == m -1 && c == n-1 ){
            return 1;
        }
        int down = dfs(r+1, c, m,n,memo);
        int right = dfs(r, c+1, m,n,memo);

        memo[r][c] = down + right;
        return memo[r][c];
    }
};
