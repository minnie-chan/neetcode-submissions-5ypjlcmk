class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        string ans = "";

        int have = 0;
        for (auto& a : t) {
            mt[a]++;
        }
        int l = 0;
        int need = mt.size();
        int minlen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            ms[s[r]]++;

            if (ms[s[r]] == mt[s[r]] && mt.count(s[r])) {
                have++;
            }
            while (need == have) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                if (mt.count(s[l]) && ms[s[l]] == mt[s[l]]) {
                    have--;
                }
                ms[s[l]]--;
                l++;
            }
        }
        if (minlen == INT_MAX) {
            return "";
        }

        return s.substr(start, minlen);
    }
};
