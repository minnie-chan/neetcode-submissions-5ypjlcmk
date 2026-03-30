class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto& zz: s){
            mp[zz]++;
        }
        for(auto& ss : t){
            mp[ss]--;
        }
        for(auto& [c,value] : mp){
            if(value != 0){
                return false;
            }
        }
        return true;
    }
};
