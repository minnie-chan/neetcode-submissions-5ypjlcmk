class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto& n : nums){
            mp[n]++;
        }

        vector<int> ans;
            int a = 0;
        for(int i = 0; i < k;i++){
            int l = 0;
            for(auto& [key,value] : mp){
                if(value > l){
                    l = value;
                    a = key;
                }
            }
            ans.push_back(a);
            mp.erase(a);
        }
        return ans;
    }
};
