class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];

        for(int i = 0; i < nums.size(); i++){
            int z = nums[i];
            ans = max(ans, z);
            for(int j = i + 1; j < nums.size(); j++){
                z *= nums[j];
                ans = max(ans,z);
            }
        }
        return ans;
    }
};
