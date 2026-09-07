class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size();i++){
            int p = target - nums[i];

            if(mp.find(p) != mp.end()){
                return {mp[p], i};

            }

            mp[nums[i]] = i;
        }
        return {};
    }
};
