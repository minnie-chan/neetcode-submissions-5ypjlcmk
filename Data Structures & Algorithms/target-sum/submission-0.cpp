class Solution {
public:
    unordered_map<string, int> memo;

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int sum, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(sum);

        if (memo.count(key)) {
            return memo[key];
        }

        int add = dfs(i + 1, sum + nums[i], nums, target);
        int subtract = dfs(i + 1, sum - nums[i], nums, target);

        memo[key] = add + subtract;
        return memo[key];
    }
};