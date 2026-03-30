class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int left = 0;
        int n = s.size();
        int ans = 0;
        for(int right = 0; right < n; right++){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
