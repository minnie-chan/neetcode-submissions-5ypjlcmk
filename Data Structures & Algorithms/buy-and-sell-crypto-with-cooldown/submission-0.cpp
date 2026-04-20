class Solution {
public:
    int ans = 0;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>> memo(n, vector<int>(2, -1));
       return dfs(0,prices,false,memo);
    }
    int dfs(int i, vector<int>& prices, bool holding,vector<vector<int>>& memo ){
        if(i >= prices.size()){
            return 0;
        }
        int skip;
        if(memo[i][holding] != -1){
            return memo[i][holding];
        }
        if(holding == false){
           skip =  dfs(i+1, prices, false, memo);
           int buy  = -prices[i] + dfs(i+1,prices, true, memo);
           ans = max(skip, buy); 
        } else if(holding == true){
            int sell = prices[i] + dfs(i+2, prices, false, memo);
            ans = max(skip, sell);
        }
        memo[i][holding] = ans;
        return ans;
    }
};
