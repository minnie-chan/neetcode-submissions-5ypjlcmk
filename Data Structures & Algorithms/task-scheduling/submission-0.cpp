class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         int freq[26] = {0};
        for (char c : tasks) freq[c - 'A']++;

        int maxFreq = 0;
        for (int f : freq) maxFreq = max(maxFreq, f);

        int numMax = 0;
        for (int f : freq) if (f == maxFreq) numMax++;

        long long frame = 1LL * (maxFreq - 1) * (n + 1) + numMax;
        return (int)max<long long>(tasks.size(), frame);
    }
};
