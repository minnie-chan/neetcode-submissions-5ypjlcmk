class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
         unordered_set<int> st;

        for(int i = start; i < nums.size(); i++){
            if(st.count(nums[i])){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[start], nums[i]);
            dfs(nums,ans, start+1);
            swap(nums[i], nums[start]);
        }

    }

};