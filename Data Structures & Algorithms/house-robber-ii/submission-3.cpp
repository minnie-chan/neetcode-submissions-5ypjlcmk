class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        } 
        int n = nums.size();
        int go = hr(nums, 0, n - 1);
        int jo = hr(nums, 1, n);

        return max(go, jo);
    }
    int hr(vector<int>& nums, int start, int end){
        int num1 = 0;
        int num2 = 0;
        for(int i = start; i < end; i++){
            int sum = nums[i] + num2;
            int skip = num1;
            int maxs = max(sum, skip);

            num2 = num1;
            num1 = maxs;
        }
        return num1;
    }
};
