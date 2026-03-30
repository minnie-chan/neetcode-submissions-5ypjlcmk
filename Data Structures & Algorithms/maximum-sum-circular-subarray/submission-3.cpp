class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0;
        int maxsum = nums[0], curMax = 0;
        int minsum = nums[0], curmin = 0;
        for(auto size: nums){
            totalsum += size;
            curMax = max(size, curMax + size);
            maxsum = max(maxsum, curMax);

            curmin = min(size, curmin + size);
            minsum = min(minsum, curmin);
        }
        if (maxsum < 0) return maxsum;
        return max(maxsum, totalsum - minsum);
    }
};