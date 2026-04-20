class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 1;j <= n; j++){
            int a = nums[(i + j-1) % n];
            sum += a;
            ans = max(ans, sum);
        }
    }

    return ans;

      
    }
};