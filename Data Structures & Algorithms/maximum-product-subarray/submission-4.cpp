class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cm = nums[0];
        int cim = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            int oldMax = cm;
            int oldMin = cim;

            cm = max(cur, max(cur * oldMax, cur * oldMin));
            cim = min(cur, min(cur * oldMax, cur * oldMin));

            ans = max(ans, cm);
        }

        return ans;
    }
};