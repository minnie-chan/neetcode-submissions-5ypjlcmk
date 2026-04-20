class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp;

        for(auto& ss: s){
            mp[ss]++;
        }
        for(auto& zz: t){
            mp[zz]--;
        }

        for(auto& [key, value]: mp){
            if (value == 0){
                return true;
        
            } else return false;
        }
        
        
    }
};
