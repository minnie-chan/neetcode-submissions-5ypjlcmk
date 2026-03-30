class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long totalSum = 0;

        long long curMax = 0, maxSum = nums[0];
        long long curMin = 0, minSum = nums[0];

        for (int x : nums) {
            totalSum += x;

            curMax = max((long long)x, curMax + x);
            maxSum = max(maxSum, curMax);

            curMin = min((long long)x, curMin + x);
            minSum = min(minSum, curMin);
        }

        if (maxSum < 0) return (int)maxSum;
        return (int)max(maxSum, totalSum - minSum);
    }
};