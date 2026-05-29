class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return dfs(0, 0, prices, memo); // day 0, not holding
    }

    int dfs(int day, int holding, vector<int>& prices, vector<vector<int>>& memo) {
        if (day >= prices.size()) {
            return 0;
        }

        if (memo[day][holding] != -1) {
            return memo[day][holding];
        }

        if (holding == 0) {
            int buy = -prices[day] + dfs(day + 1, 1, prices, memo);
            int skip = dfs(day + 1, 0, prices, memo);

            memo[day][holding] = max(buy, skip);
        } else {
            int sell = prices[day] + dfs(day + 2, 0, prices, memo);
            int hold = dfs(day + 1, 1, prices, memo);

            memo[day][holding] = max(sell, hold);
        }

        return memo[day][holding];
    }
};