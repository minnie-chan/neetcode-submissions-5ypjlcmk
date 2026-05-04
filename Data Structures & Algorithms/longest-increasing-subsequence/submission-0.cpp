class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n ,-1);
        int best = 0;
        for(int i = 0; i < nums.size();i++){
            best = max(best,dfs(i,nums,memo));
        }
        return best;
    }
    int dfs(int i, vector<int>& nums, vector<int>& memo){
        if(memo[i] != -1){
            return memo[i];
        }
        int best = 1;

        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] > nums[i]){
                best = max(best, 1+dfs(j, nums,memo));
            }
        }
        memo[i] = best;
        return best;
    }
};
