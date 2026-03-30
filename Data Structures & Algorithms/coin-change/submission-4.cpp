class Solution {
public:
    static constexpr int INF = 1000000000;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);
        int ans = dfs(amount, coins, memo);
        if(ans >= INF){
            return  -1;
        } else {
            return ans;
        }
    }
    int dfs(int rem, vector<int>& coins, vector<int>& memo){
        
        if(rem == 0){
            return 0;
        } else if(rem < 0){
          return INF;
        }
        if(memo[rem] != -2){
            return memo[rem];
        }
        int best = INF;
        for(auto& c: coins){
            int result = dfs(rem - c, coins, memo);
            if(result != INF){
                best = min(best, result + 1);
            }
        }
        memo[rem] = best;
        return best;
    }
};
