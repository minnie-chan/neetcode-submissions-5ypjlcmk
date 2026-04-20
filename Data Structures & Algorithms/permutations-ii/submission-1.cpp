class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,ans,0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans,
             int start){
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            swap(nums[start], nums[i]);
            dfs(nums,ans, i+1);
            swap(nums[start], nums[i]);
        }
    }

};