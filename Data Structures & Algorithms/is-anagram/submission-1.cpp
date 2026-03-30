class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) return false; 
        unordered_map<char,int> app;


        for (char ch : s) app[ch]++;
        for (char ch : t) app[ch]--; 
        for(const auto &[ch,count] : app){
            if(count != 0){
                return false;
            } 
            
        }
        
        return true;
        }
        
    };
