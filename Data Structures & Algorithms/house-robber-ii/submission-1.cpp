class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];


        int case1 = robRange(nums, 0, nums.size() - 2);

        int case2 = robRange(nums, 1, nums.size() - 1);

        return max(case1, case2);
        
    }
    int robRange(vector<int>& nums, int start, int end) {
    int num1 = 0, num2 = 0;
    for (int i = start; i <= end; i++) {
        int add = nums[i] + num2;
        int skip = num1;
        int m = max(add, skip);
        num2 = num1;
        num1 = m;
    }
    return num1;
    }

};

    
