class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int lastEnd = in[0][1];

        for (int i = 1; i < in.size(); i++) {
            if (in[i][0] >= lastEnd) {
                lastEnd = in[i][1];
            } else {
                count++;
            }
        }

        return count;
    }
};
