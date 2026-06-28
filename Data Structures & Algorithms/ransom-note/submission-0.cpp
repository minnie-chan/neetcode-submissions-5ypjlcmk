class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for (auto& c : magazine) {
            mp[c]++;
        }

        for(auto& r : ransomNote){
            char a = r;
            if(mp.find(a) != mp.end()){
                if(mp[a] <= 0){
                    return false;
                }
                mp[r]--;
            } else{
                return false;
            }
        }
        return true;
    }
};