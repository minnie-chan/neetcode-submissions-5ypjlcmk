class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto& size: nums){
            mp[size]++;
        }
        for(auto& [key,value] : mp){
            if(value >= k){
                ans.push_back(key);
            }
        }
        return ans;
    }
};
