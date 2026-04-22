class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int bestStart = 0;
        int bestLen = 1;

        // length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length 2 and more
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && len > bestLen) {
                    bestLen = len;
                    bestStart = i;
                }
            }
        }

        return s.substr(bestStart, bestLen);
    }
};