class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
         
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0){
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    
                    while( l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                    while( r > l && nums[r] == nums[r + 1]){
                        r--;
                    }
                }
                if(sum < 0){
                    l++;
                }else if(sum > 0){
                    r--;
                }
            }
        }
        return ans;
    }
};
