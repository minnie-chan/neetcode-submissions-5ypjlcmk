class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto& n : nums){
            mp[n]++;
        }

        int curr = 0;
        int b = 0;
        for(int i = 0; i < k; i++){
            curr = 0;
            for(auto& [key,value]: mp){
                if(curr < value){
                    curr = value;
                    b = key;
                }
            }
            ans.push_back(b);
            mp.erase(b);
        }
        return ans;
    }
};
