class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            int sub = target - nums[i];
            if(mp.find(sub) != mp.end()){
                return{mp[nums[i]], i};/// idk how to do the reutrn type this the only thing that confuses me 
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
