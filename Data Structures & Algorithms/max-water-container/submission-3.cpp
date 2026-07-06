class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r =  h.size() - 1;
        int width = 0;
        int length = 0;
        int ans = 0;

        while(l < r){
            width = r - l;
            length = min(h[l], h[r]);
            
            ans = max(ans, width * length);

            if(h[l] < h[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
