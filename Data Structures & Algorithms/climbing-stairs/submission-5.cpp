class Solution {
public:
    int climbStairs(int n) {
        if(n == 0){
            return n;
        }
        vector<int> memo(n + 1, -1);
        return dfs(0,n,memo);
    }
    int dfs(int i, int n, vector<int>& memo){
            if (i == n) {
            return 1;
        }

        if (i > n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        


        memo[i] = dfs(i + 1, n, memo) + dfs(i + 2, n, memo);
        return memo[i];
    }
};
