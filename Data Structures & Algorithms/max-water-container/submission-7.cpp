class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int ans = 0;

        while(l < r){
            int width = r - l;
            int height = min(h[r],h[l]);
            ans = max(ans, width * height);

            if(h[l] > h[r]){
                r--;;
            } else {
                l++;
            }
        }
        return ans;
    }
};
