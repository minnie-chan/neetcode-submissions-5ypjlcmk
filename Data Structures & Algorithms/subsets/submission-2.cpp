class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> hold;
        dfs(0,nums,ans,hold);
        return ans;
    }   
    void dfs(int start, vector<int>& nums,vector<vector<int>>& ans,vector<int>& hold ){
        ans.push_back(hold);

        for(int i = start; i < nums.size(); i++){
            hold.push_back(nums[i]);

            dfs(i + 1, nums, ans, hold);
            hold.pop_back();
        }
    }
};
