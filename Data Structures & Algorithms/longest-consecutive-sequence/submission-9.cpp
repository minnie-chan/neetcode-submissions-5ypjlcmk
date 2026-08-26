class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int length = 1;
        int ans = 0;
        int x = 0;
        unordered_set<int> st;
        for (auto& n : nums) {
            st.insert(n);
        }
        for (auto& key : st) {
            x = key;

            if (st.find(x - 1) != st.end()) {
                continue;
            } else {
                while (st.find(x + 1) != st.end()) {
                    length++;
                    x = x + 1;
                }
            }
            ans = max(ans, length);
            length = 1;
        }
        return ans;
    }
};
