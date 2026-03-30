class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            int sum = i + nums[i];
            if(sum >= a){
                a = i;
            }
        }
        return a == 0;
    }
};
