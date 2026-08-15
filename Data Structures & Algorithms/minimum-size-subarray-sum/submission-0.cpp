// What does my window represent? the legnth 
// What should r do? move when the sum is  <= target
// When is my window valid?when its greate then or equal to taarget  
// When should l move? when we are >= the the target becuase we wan the min size 
// Am I looking for the minimum or maximum window? min 
// What information do I need to maintain? the sum and length
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int r = 0; r < nums.size();r++){
            sum += nums[r];
            
            while(sum >= target){
                ans = min(ans, r - l + 1);

                sum -= nums[l];
                l++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }

};