class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto& n : nums) {
            mp[n]++;
        }

        int longest = 0;

        for (auto& [key, value] : mp) {
            // only start from beginning of sequence
            if (mp.find(key - 1) == mp.end()) {
                int current = key;
                int count = 1;

                while (mp.find(current + 1) != mp.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};