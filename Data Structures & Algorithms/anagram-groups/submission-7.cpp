class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto& s : strs){
            string a = s;
            sort(s.begin(), s.end());

            mp[s].push_back(a);
        }

        for(auto& [key,value] : mp){
            ans.push_back(value);
        }
        return ans;
    }
};
