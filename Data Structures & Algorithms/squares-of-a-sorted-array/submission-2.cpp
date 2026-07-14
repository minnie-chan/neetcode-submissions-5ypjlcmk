class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int pos = nums.size() - 1;
        vector<int> ans(nums.size());

        while(l <= r){
            int a = nums[l] * nums[l];
            int b = nums[r] * nums[r];

            if(a > b){
                ans[pos] = a;
                l++;
            } else {
                ans[pos] = b;
                r--;
            }
            pos--;
        }
        return ans;
    }
};