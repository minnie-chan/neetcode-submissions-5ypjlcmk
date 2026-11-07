class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int l = 0;
        int r = 0;
        int track = 0;

        for (int r = 0; r < nums.size(); r++) {
            track += nums[r];
            
            while (track >= target) {
                ans = min(ans, r - l + 1);
                track -= nums[l];
                l++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};