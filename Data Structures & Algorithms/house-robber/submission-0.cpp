class Solution {
public:
    int rob(vector<int>& nums) {
        
        int num1 = 0;
        int num2 = 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        for(int i = 0; i < nums.size(); i++){
           int take = nums[i] + num2;
           int hold = num1;
           int maxs = max(take, hold);
           num2 = num1;
           num1 = maxs;

        }
        return num1;
    }
    
};
