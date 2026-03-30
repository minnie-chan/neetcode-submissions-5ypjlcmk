class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            freq[c]++;

            while (freq[c] > 1) {            // window invalid (duplicate of c)
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
