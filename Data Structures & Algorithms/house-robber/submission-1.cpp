class Solution {
public:
    int rob(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;

        for(int i = 0; i < nums.size(); i++){
            int add = nums[i] + num2;
            int skip = num1;
            int m = max(add,skip);

            num2 = num1;
            num1 = m;
        }
        return num1;
    }
};
