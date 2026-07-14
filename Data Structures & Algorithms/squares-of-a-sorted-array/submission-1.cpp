class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0;
        int r = nums.size() - 1;
        int pos = nums.size() - 1;

        while(l <= r){
            int leftSquare = nums[l] * nums[l];
            int rightSquare = nums[r] * nums[r];
            
            if(leftSquare > rightSquare){
                ans[pos] = leftSquare;
                l++;
            } else {
                ans[pos] = rightSquare;
                r--;
            }
            pos--;
        }
        return ans;
    }
};