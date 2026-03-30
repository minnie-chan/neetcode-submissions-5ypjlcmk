class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
    bool dfs(vector<int>& nums, int i){
        if(i >= nums.size() -1){
            return true;
        }
        int n = nums.size();
        int a = min(n - 1, i + nums[i]);
        for(int j = i + 1; j <= a; j++ ){
            if(dfs(nums, j) == true){
                return true;
            }
        }
        return false;
    }
};
