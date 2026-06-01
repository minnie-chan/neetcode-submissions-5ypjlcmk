class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> memo;
        return dfs(0,0,nums,target,memo);
    }
    int dfs(int i, int rm, vector<int>& nums, int target,
            unordered_map<string,int>& memo){
        
        if(i == nums.size()){
            return rm == target ? 1 : 0;
        }
        string a = to_string(i) + "," + to_string(rm);
        if(memo.count(a)){
            return memo[a];
        }

        int add = dfs(i+1,rm + nums[i],nums,target,memo);
        int minus = dfs(i+1,rm - nums[i],nums,target,memo);

        memo[a] = add + minus;
        return memo[a];
    }
};
