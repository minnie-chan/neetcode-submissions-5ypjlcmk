class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        char n;
        for(auto& a : s){
            mp[a]++;
        }
        
        for(auto& b : t){
            mp[b]--;
        }

        for(auto& [key,value] : mp){
            if(value != 0){
                n = key;
            }
        }
        return n;
    }
};