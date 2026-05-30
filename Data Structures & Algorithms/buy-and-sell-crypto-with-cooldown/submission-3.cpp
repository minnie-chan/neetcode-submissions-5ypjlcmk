class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> vec(prices.size(), vector<int>(2, -1));
        return dfs(0,0,prices,vec);

    }
    int dfs(int day, int holding, vector<int>& prices, vector<vector<int>>& vec){
        if(day >= prices.size()){
            return 0;
        }
        if(vec[day][holding] != -1){
            return vec[day][holding];
        }

        if(holding == 0){
            int buy = -prices[day] + dfs(day + 1, 1, prices, vec);
            int skip = dfs(day + 1,0, prices, vec);

            vec[day][holding] = max(buy,skip);
        } else {
            int sell = prices[day] + dfs(day + 2,0,prices,vec);
            int hold = dfs(day+1, 1, prices,vec);

            vec[day][holding] = max(sell,hold);
        }
        return vec[day][holding];
    }
};
