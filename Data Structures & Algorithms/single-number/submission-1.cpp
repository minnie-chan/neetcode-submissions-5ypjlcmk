class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(auto& push : nums){
            ans ^= push;
            
        }
      return ans;
    }
};
