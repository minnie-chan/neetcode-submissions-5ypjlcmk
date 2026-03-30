class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> slave;
        dfs(nums,ans,slave,target,0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans,
             vector<int>& slave, int rmg,int start){
        if(rmg == 0){
            ans.push_back(slave);
            return;
        }
        //if(rmg < 0){return;}
        for(int j = start; j < nums.size(); j++){
            if (nums[j] > rmg) break;
            slave.push_back(nums[j]);
            dfs(nums, ans, slave, rmg - nums[j], j);
            slave.pop_back();
        }
    }
};
