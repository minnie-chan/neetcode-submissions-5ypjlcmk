class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto& push : nums){
            mp[push]++;
            
        }

        for(auto& [key,value] : mp){
            if(value == 1) return key; 
        }
      
    }
};
