class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        int ans = 0;
        int track = 0;
        for (auto& n : nums) {
            se.insert(n);
        }

        for (auto& k : se) {
            if (se.find(k - 1) == se.end()) {
                int track = 1;
                int current = k;

                while (se.find(current+1) != se.end()) {
                    track++;
                    current++;
                }

                ans = max(ans, track);
            }
        }
        return ans;
    }
};
