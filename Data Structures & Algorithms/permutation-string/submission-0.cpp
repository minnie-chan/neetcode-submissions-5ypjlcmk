class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int l = 0;

        for (auto& a : s1) {
            need[a]++;
        }

        for (int i = 0; i < s2.size(); i++) {
            window[s2[i]]++;

            if (i - l + 1 > s1.size()) {
                window[s2[l]]--;
                if (window[s2[l]] == 0) {
                    window.erase(s2[l]);
                }
                l++;
            }

            if (i - l + 1 == s1.size()) {
                if (need == window) {
                    return true;
                }
            }
        }
        return false;
    }
};
