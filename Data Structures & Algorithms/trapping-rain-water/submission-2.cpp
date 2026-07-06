class Solution {
public:
    int trap(vector<int>& h) {
        

        int ans = 0;
        for(int i = 0 ; i < h.size();i++){
            int lm = 0;
            int rm = 0;
            for(int a = 0; a < i; a++){
                lm = max(lm, h[a]);
            }

            for(int b = i + 1; b < h.size(); b++){
                rm = max(rm, h[b]);
            }

            int waterLevel = min(lm, rm);

            if (waterLevel > h[i]) {
                ans += waterLevel - h[i];
            }
            
        }

        return ans;
    }
};
