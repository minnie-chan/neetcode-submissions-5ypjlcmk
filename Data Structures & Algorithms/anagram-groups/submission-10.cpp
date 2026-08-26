class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto& s : strs){
            string a = s;
            sort(a.begin(), a.end());
            mp[a].push_back(s);
        }
        vector<vector<string>> ans;
        
        for(auto& [key,value]: mp){
            ans.push_back(value);
        }
        return ans;
    }
};
