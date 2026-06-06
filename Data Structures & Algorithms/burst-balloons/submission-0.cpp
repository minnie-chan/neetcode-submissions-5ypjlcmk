class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(nums.size(),vector<int>(nums.size(),-1));
        return dfs(0,nums.size() - 1, nums,memo);
    }
    int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& memo){
        if(i + 1 == j){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int ans = 0;
        for(int k = i + 1; k < j; k++){
            int best = dfs(i,k,nums,memo) +
                nums[i] * nums[k] * nums[j] +
                dfs(k,j,nums,memo);
            ans = max(ans,best);
        }
        return memo[i][j] = ans;
    }
};
