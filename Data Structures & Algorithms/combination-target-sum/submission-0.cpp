class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> vc;
        dfs(nums, 0 , ans, vc, target);
        return ans;
    }
    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans, 
             vector<int>& vc, int remain_goal){
        
        if(remain_goal == 0){
            ans.push_back(vc);
            return;
        } 
        
        for(int j = start; j < nums.size(); j++){
            if (nums[j] > remain_goal) break;
            vc.push_back(nums[j]);
            dfs(nums, j , ans, vc , remain_goal - nums[j] );
            vc.pop_back();
        }
    }
};
