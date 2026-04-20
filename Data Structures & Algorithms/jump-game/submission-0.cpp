class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        for(int i = 0; i < nums.size();){
            if(nums[i] > 0){
                i += nums[i];
            }
            if(nums[i] == 0){
                return false;
            }
            if(nums[i] - 1 == 0){
                    return true;
            }
        }
        return true;
    }
};
