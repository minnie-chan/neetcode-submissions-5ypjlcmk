class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> memo(s.size(), vector<long long>(t.size(), -1));
        return dfs(0, 0, s, t, memo);
    }

    long long dfs(int i, int j, string& s, string& t, vector<vector<long long>>& memo) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        long long ways = dfs(i + 1, j, s, t, memo); // skip s[i]

        if (s[i] == t[j]) {
            ways += dfs(i + 1, j + 1, s, t, memo); // use s[i]
        }

        return memo[i][j] = ways;
    }
};