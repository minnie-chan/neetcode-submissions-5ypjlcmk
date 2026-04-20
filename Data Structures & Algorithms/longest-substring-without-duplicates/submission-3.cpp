class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            int a = mp[s[right]]++;

            if(a > 1){
                a - 1;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
