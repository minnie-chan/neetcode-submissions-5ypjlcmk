class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
            unordered_map<char,int> mp;

            for(char cs : s) mp[cs]++;
            for(char cs : t) mp[cs]--;

            for(const auto &[cs, count]: mp){
               if(count != 0){
                return false;
               } 
            }
            return true;
        }
        
    };
