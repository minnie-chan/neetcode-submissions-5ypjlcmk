class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int ans = 0;
        int width = 0;
        int height = 0;

        while (l < r) {
            width = r - l;
            height = min(h[l], h[r]);

            ans = max(ans, width * height);

            if (h[l] < h[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
