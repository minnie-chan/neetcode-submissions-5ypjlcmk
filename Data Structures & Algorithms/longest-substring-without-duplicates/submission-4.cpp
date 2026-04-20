class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;

            if(mp[s[right]] > 1){
                mp[s[right]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
