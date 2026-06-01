class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(0, 0, s1, s2, s3, memo);
    }

    bool dfs(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& memo) {
        int k = i + j;

        if (k == s3.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool yn = false;

        if (i < s1.size() && s1[i] == s3[k]) {
            yn = yn || dfs(i + 1, j, s1, s2, s3, memo);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            yn = yn || dfs(i, j + 1, s1, s2, s3, memo);
        }

        return memo[i][j] = yn;
    }
};