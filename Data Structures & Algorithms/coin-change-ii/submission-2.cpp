class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> vec(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0,amount,coins,vec);
    }
    int dfs(int i,int amount, vector<int>& coins,vector<vector<int>>& vec){
        if(i >= coins.size()){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(amount < 0){
            return 0;
        }
        if (vec[i][amount] != -1) {
            return vec[i][amount];
        }


        int use = dfs(i, amount - coins[i], coins, vec);
        int skip = dfs(i + 1, amount, coins, vec);

        vec[i][amount] = use + skip;
        return vec[i][amount];
    }
};
