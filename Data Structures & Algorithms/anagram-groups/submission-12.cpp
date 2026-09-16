class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto& s : strs){
            string a = "";
            a = s;
            sort(s.begin(),s.end());
            
            mp[s].push_back(a);
        }

        vector<vector<string>> ans;

        for(auto& [key,value] : mp){
            ans.push_back(value);
        }
        return ans;
    }
};
