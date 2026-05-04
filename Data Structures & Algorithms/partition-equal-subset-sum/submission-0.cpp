class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return dfs(0, target, nums, memo);
    }
    bool dfs(int i, int target, vector<int>& nums, vector<vector<int>> & memo){
        if(target == 0){
            return true;
        }
        if(i == nums.size() || target < 0){
            return false;
        }
        if (memo[i][target] != -1) {
            return memo[i][target];
        }
        bool take = dfs(i + 1, target - nums[i], nums, memo);
        bool skip = dfs(i + 1, target, nums, memo);

        memo[i][target] = take || skip;

        return memo[i][target];
    }
};
