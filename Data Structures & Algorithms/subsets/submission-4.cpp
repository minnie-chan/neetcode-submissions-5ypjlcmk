class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> track;
        dfs(0,nums,ans,track);
        return ans;
    }
    void dfs(int travel,vector<int>& nums, vector<vector<int>>& ans, vector<int>& track){
        ans.push_back(track);

        for(int i = travel; i < nums.size(); i++){
            track.push_back(nums[i]);

            dfs(i + 1, nums, ans, track);

            track.pop_back();
        }
    }
};
