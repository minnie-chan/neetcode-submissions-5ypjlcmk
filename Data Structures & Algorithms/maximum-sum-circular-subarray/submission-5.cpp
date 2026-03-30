class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        for(int x: nums){
            total += x;

            curMax = max(x, x + curMax);
            maxSum = max(maxSum, curMax);

            curMin = min(x, x + curMin);
            minSum = min(minSum, curMin);
        }
        if(maxSum < 0 ){
            return maxSum;
        }
        return max(maxSum, total - minSum);
    }
};