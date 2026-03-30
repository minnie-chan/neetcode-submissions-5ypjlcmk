class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> vc;
        dfs(0,nums,ans,vc);
        return ans;
    }
    void dfs(int move, vector<int>& nums, vector<vector<int>>& ans,vector<int>& vc){

        ans.push_back(vc);

        for(int i = move; i < nums.size(); i++){
            
            if(i > move && nums[i - 1] == nums[i]){
                continue;
            }
            vc.push_back(nums[i]);

            dfs(i + 1,nums,ans,vc);

            vc.pop_back();
        }
    }
};
