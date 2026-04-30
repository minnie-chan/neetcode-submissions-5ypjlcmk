class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m =  nums[0];
        int mi = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];

            int oldm = m;
            int oldmi = mi;

            m = max(x, max(x * oldm, x * oldmi));
            mi = min(x, min(x * oldm, x* oldmi));

            ans = max(ans, m);
        }
        return ans;
    }
};
