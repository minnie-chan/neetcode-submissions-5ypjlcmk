class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int b = j + 1;
                int k = n - 1;

                while (b < k) {
                    long long sum = (long long)nums[i] + nums[j] + nums[b] + nums[k];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[b], nums[k]});
                        b++;
                        k--;

                        while (b < k && nums[b] == nums[b - 1]) b++;
                        while (b < k && nums[k] == nums[k + 1]) k--;
                    } else if (sum < target) {
                        b++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};