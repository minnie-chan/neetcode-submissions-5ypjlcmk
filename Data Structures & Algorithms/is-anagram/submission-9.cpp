class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <int,int> mp;

        for(auto& size: s){
            mp[size]++;
        }

        for(auto& size: t){
            mp[size]--;
        }

        for(auto& [key,value] : mp){
            if(value != 0){
                return false;
            }
        }
        return true;
    }
};
