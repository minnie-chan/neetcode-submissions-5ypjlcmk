class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto& n : nums){
            mp[n]++;
        }

        vector<int> vec;
        int maxFreq = 0;
        int maxKey = 0;


        for(int i = 0; i < k; i++){
            maxFreq = 0;
            maxKey = 0;
            for (auto& [key, value] : mp) {
                if (value > maxFreq) {
                    maxFreq = value;
                    maxKey = key;
                }
            }
            vec.push_back(maxKey);
            mp.erase(maxKey);
        }
        return vec;
    }
};
