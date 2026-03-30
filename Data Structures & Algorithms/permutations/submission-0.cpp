class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,ans,0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans,int start ){
        
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        }


        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);

            dfs(nums,ans, start + 1);

            swap(nums[i], nums[start]);
            
        }
    }
};
