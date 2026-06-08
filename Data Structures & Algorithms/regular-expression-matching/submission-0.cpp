class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p, memo);
    }
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = dfs(i, j + 2, s, p, memo) || 
                (firstMatch && dfs(i + 1, j, s, p, memo));
        } else {
            ans = firstMatch && dfs(i + 1, j + 1, s, p, memo);
        }

        return memo[i][j] = ans;
    }
};
