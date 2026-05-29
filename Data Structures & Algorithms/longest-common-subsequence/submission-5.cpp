class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0,0,text1,text2,memo);
    }
    int dfs(int r,int c,string text1,string text2,vector<vector<int>>& memo){
        if(r >= text1.size() || c >= text2.size()){
            return 0;
        }
        if(memo[r][c] != -1){
            return memo[r][c];
        }


        if(text1[r] == text2[c]){
            memo[r][c] = 1 + dfs(r+1,c+1,text1,text2,memo);
        } else {
            memo[r][c] = max(dfs(r+1,c,text1,text2,memo),
                             dfs(r,c+1,text1,text2,memo));
        }
        return memo[r][c];
    }
};
