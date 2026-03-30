class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto& size: strs){
            string key = size;
            sort(key.begin(), key.end());
            mp[key].push_back(size);
        }
        for(auto& ap: mp){
            ans.push_back(ap.second);
            
        }
        return ans;
    }
};
