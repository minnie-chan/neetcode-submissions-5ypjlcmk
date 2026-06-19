class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(auto& a : strs){
            string b = a;
            sort(b.begin(), b.end());
            mp[b].push_back(a);
        }
        vector<vector<string>> vec;

        for(auto& [key,value] : mp){

            vec.push_back(value);
        }
        return vec;
    }
};
