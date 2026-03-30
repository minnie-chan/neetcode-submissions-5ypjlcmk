class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        } else if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        int domain = robRange(nums, 0, n-2);
        int expansion = robRange(nums, 1, n-1);

        return max(domain, expansion);
    }
    int robRange(vector<int>& nums, int start, int end){
        int num1 = 0;
        int num2 = 0;
        for(int i = start; i <= end; i++){
            int sum = nums[i] + num2;
            int skip = num1;
            int maxs = max(sum, skip);

            num2 = num1;
            num1 = maxs;
        }
        return num1;
    }
};
