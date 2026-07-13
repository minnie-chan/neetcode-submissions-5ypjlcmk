class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto& a : strs){
            string b = a;
            sort(b.begin(), b.end());

            mp[b].push_back(a);
        }

        for(auto& [key,value] : mp){
            ans.push_back(value);
        }
        return ans;
    }
};
