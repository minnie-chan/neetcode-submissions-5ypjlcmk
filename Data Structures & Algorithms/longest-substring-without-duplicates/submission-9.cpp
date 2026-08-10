// window represents: the legnth of the loongest substring
// map stores: char,int
// r does: it moves to the rigth and at the same time its checking for duplicates
// l does: it moves up by 1 when we find a dduplice
// window becomes invalid when:we find a duplicate in our current window
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            // expand with r
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                // shrink with l
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            // calculate valid window length
        }
        return ans;
    }
};
