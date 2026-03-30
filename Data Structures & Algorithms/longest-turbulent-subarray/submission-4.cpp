class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int best = 1;
        int len = 1;
        int prev = 0;

        for (int j = 1; j < n; j++) {
            int cur = sign(arr[j - 1], arr[j]);

            if (cur == 0) {
                len = 1;
            } else if (prev == 0 || cur == prev) {
                len = 2;
            } else {
                len++;
            }

            prev = cur;              // update once, every time
            best = max(best, len);
        }

        return best;
    }

    int sign(int a, int b) {
        if (a < b) return 1;
        if (a > b) return -1;
        return 0;
    }
};
