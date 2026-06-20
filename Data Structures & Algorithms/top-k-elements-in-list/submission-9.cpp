class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto& n : nums){
            mp[n]++;
        }
        vector<int> vec;
        int maxfreq = 0;
        int maxKey = 0;
        for(int i = 0; i < k; i++){
            maxfreq = 0;
            for(auto& [key,value] : mp){
                if(value > maxfreq){
                    maxfreq = value;
                    maxKey = key;
                }
            }
            vec.push_back(maxKey);
            mp.erase(maxKey);
        }
        return vec;
    }
};
