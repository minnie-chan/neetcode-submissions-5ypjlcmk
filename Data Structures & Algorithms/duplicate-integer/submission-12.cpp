class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(auto& zz : nums){
            mp[zz]++;
        }

        for(auto& [c,z] : mp){
            if(z != 1){
                return true;
            }
        }
        return false;
    }
};