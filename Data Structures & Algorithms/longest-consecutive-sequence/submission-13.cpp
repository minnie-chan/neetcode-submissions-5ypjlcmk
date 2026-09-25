class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if (nums.size() == 0) {
            return 0;
        }

        for (auto& n : nums) {
            st.insert(n);
        }

        int best = 1;

        for (auto& num : nums) {
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                best = max(best, count);
            }
        }
        return best;
    }
};
