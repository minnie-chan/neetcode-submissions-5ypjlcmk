class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int best = 0;

        for(int i = 0; i < s.size();i++){


            while (st.find(s[i]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            best = max(best, i - left + 1);
            st.insert(s[i]);
        }
        return best;
    }
};
