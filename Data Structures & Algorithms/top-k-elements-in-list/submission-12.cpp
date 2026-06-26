class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int a) {
        unordered_map<int,int> mp;

        for(auto& n : nums){
            mp[n]++;
        }
        vector<int> ans;
        int h = 0;
        int k = 0;
        for(int i = 0; i < a; i++){
                h = 0;
            for(auto& [key,value] : mp){
                if(value > h){
                    h = value;
                    k = key;
                }
            }
            ans.push_back(k);
            mp.erase(k);
        }
        return ans;
    }
};
