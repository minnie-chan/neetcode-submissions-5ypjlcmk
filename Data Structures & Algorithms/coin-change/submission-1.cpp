class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        const int INF = 1e9;
        //how would we return this ?
        int ans = dfs(amount, coins);
        if(ans == INF){
            return  -1;
        } else {
            return ans;
        }
    }
    int dfs(int rem, vector<int>& coins){
        const int INF = 1e9;
        if(rem == 0){
            return 0;
        } else if(rem < 0){
          return INF;
        }
        int best = INF;
        for(auto& c: coins){
            int result = dfs(rem - c, coins);
            if(result != INF){
                best = min(best, result + 1);
            }
        }
        return best;
    }
};
