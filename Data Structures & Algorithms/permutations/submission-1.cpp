class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
                
        dfs(0,nums,ans);
        return ans;
    }
    void dfs(int move, vector<int>& nums, vector<vector<int>>& ans){

        if(move == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = move; i < nums.size(); i++){

            swap(nums[move], nums[i]);

            dfs(move+1, nums, ans);

            swap(nums[move], nums[i]);
        }
    }
};
