class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>> memo(n, vector<int>(2, -1));
       return dfs(0,prices,false,memo);
    }
    int dfs(int i, vector<int>& prices, bool holding,vector<vector<int>>& memo ){
        if(i >= prices.size()){
            return 0;
        }
        
        int h = holding ? 1 : 0;
        if(memo[i][h] != -1){
            return memo[i][h];
        }
        int skip = dfs(i+1, prices, holding,memo);
        int ans = skip;
        if(holding == false){
           int buy  = -prices[i] + dfs(i+1,prices, true, memo);
           ans = max(ans, buy); 
        } else if(holding == true){
            int sell = prices[i] + dfs(i+2, prices, false, memo);
            ans = max(ans, sell);
        }
        memo[i][h] = ans;
        return ans;
    }
};
