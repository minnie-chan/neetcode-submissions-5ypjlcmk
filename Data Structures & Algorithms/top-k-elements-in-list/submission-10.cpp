class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(auto& n : nums){
            mp[n]++;
        }
        int b = 0;
        for(int i = 0; i < k; i++){// couldnt explain why we iteerae throug k 
            int a = 0;

            for(auto& [key,value] : mp){
                if(value > a){
                    a = value;
                    b = key;
                }
            }
            ans.push_back(b);
            mp.erase(b);
        }
        return ans;
    }
};
