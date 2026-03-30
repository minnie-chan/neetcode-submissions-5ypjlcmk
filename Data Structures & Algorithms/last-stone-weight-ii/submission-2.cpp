class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
          int S = 0;
        for (int x : stones) S += x;
        int half = S / 2;
        int n = stones.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
        dp[0][0] = true; 

        for (int i = 1; i <= n; i++) {
            int w = stones[i - 1];
            for (int j = 0; j <= half; j++) {
                dp[i][j] = dp[i - 1][j]; 
                if (j >= w) dp[i][j] = dp[i][j] || dp[i - 1][j - w];
            }
        }

        for (int j = half; j >= 0; j--) {
            if (dp[n][j]) {
                return S - 2 * j;
            }
        }
        return 0; 
    }
};