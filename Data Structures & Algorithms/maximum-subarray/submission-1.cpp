class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = nums[0];
        int b = 0;
        for(int i: nums){
            if(b < 0){
                b = 0;
            }
            b += i;
            a = max(a, b);
        }
        return a;
    }
};
