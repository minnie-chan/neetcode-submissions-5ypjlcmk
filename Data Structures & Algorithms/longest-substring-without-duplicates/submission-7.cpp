class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0;
        int longest = 0;

        for (int j = 0; j < s.size(); j++) {

            mp[s[j]]++;
            
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
         
            longest = max(longest,j - i + 1);
        }
        return longest;
    }
};
