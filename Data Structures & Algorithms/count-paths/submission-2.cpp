class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n, -1));
        return dfs(0,0,m,n,vec);
    }
    int dfs(int r,int c, int m, int n, vector<vector<int>>& vec){
        if(r >= m || c >= n){
            return 0;
        }
        if(vec[r][c] != -1){
            return vec[r][c];
        }
        if(r == m - 1 && c == n - 1){
            return 1;
        }


        int right = dfs(r+1,c,m,n,vec);
        int down = dfs(r,c+1,m,n,vec);
        vec[r][c] = right + down;
        return vec[r][c];
    }

};
