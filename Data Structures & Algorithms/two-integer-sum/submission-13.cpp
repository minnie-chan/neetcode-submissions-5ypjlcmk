class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int>mp ;
        for(int i = 0; i < nums.size(); i++){
            int meow = target - nums[i];
            if(mp.find(meow) != mp.end()){
                return { mp[meow] , i };
            }
            mp[nums[i]] = i;
        }
    }
};
