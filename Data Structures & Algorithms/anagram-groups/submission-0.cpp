class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> mp;
         for(auto& s: strs){
            string minni = s;
            sort(s.begin(), s.end());
            mp[s].push_back(minni);

         }
         for(auto& vec : mp){
            output.push_back(vec.second);
                
            
         }
         return output;
    }
};
