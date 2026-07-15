class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for(int i = 0; i < nums.size();i++){
            int l = i - 1;
            int r = i + 1;

            while(r < nums.size() ){

                ans[i] *= nums[r];
                r++;
            } 
            while(l >= 0 ){

                ans[i] *= nums[l];
                l--;
            } 
            
        }
        return ans;
    }
};
