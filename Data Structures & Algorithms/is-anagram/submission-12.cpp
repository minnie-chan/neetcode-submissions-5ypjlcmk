class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;

        for(auto& a : s){
            mp[a]++;
        }

        for(auto& b : t){
            mp[b]--;
        }

        for(auto& [key,value] : mp){
            if(value != 0){
                return false;
            }
        }
        return true;
    }
};
