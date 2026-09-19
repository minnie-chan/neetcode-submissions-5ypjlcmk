class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> vec(r.size(), 1);

        for (int i = 1; i < r.size(); i++) {
            if (r[i] > r[i - 1]) {
                vec[i] = vec[i - 1] + 1;
            }
        }

        for (int i = r.size() - 2; i >= 0; i--) {
            if (r[i] > r[i + 1]) {
                vec[i] = max(vec[i], vec[i + 1] + 1);
            }
        }

        int ans = 0;

        for (int i = 0; i < vec.size(); i++) {
            ans += vec[i];
        }

        return ans;
    }
};