class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        } else if(nums.size() == 1){
            return nums[1];
        }
        int num1 = 0;

        int num2 = 0;
        for(int i = 0; i <= nums.size(); i++){
            int sum = nums[i] + num2;
            int skip = num1;
            int maxs = max(sum, skip);

            num2 = num1;
            num1 = maxs;
            
        }
        return num1;
    }
};
