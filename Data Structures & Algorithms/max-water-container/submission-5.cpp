class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int width = 0;
        int height = 0;
        int ans = 0;

        while(l < r){
            width = r - l;
            height = min(heights[l],heights[r]);

            ans = max(ans, width * height);
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
