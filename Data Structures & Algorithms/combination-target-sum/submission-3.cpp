class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> track;
        dfs(0,nums,target,ans,track);
        return ans;
    }
    void dfs(int travel, vector<int>& nums, int& target,vector<vector<int>>& ans,vector<int>& track ){
        

        for(int i = travel; i < nums.size(); i++){
            track.push_back(nums[i]);
            
            dfs(i + 1, nums,target,ans,track);
            if(track[i] == target){
                ans.push_back(track);
            }    
            track.pop_back(); 
        }
    }
};
