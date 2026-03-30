class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> mp;
        for(auto& ss : strs){
            string po = ss;
            sort(po.begin() , po.end());
            mp[po].push_back(ss);
        }
            vector<vector<string>> result;
        for(auto& zz : mp){
            result.push_back(zz.second);
        }
        return result;
    }
};
