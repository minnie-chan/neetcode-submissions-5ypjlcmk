class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto& a : strs){
            string z = a;
            sort(a.begin(), a.end());
            string d = a;
            mp[d].push_back(z);
        }

        vector<vector<string>> ans;

        for(auto& [key,value] : mp){
            ans.push_back(value);

        }
        return ans;
    }
};
