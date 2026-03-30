class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), - 1);
        return dfs(nums,0,memo);   
    }
    int dfs(vector<int>& nums, int i,vector<int>& memo){
        if(i == nums.size() - 1){
            return 0;
        }

        if(memo[i] != -1){
            return memo[i];
        }
        int best = 1e9;
        int n = nums.size();
        int far = min(n-1, i + nums[i]);
        for(int j = i + 1; j <= far; j++){
            best = min(best, 1 + dfs(nums,j,memo));
        }
        memo[i] = best;
        return best;
    }
};
