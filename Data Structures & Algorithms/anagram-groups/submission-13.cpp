class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto& s : strs){
            string hold = s;
            sort(hold.begin(), hold.end());

            mp[hold].push_back(s);
        }
        vector<vector<string>> st;

        for(auto& [key,value] : mp){
            st.push_back(value);
        }
        return st;
    }   
};
