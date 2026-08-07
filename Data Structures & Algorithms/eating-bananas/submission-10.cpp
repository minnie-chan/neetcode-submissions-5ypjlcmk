class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(l <= r){
            int middle = l + (r - l) / 2;

            int a = math(piles, middle);
            if(a <= h){
                ans = middle;
                r = middle - 1;

            } else if(a > h){
                l = middle + 1;
            }
        }
        return ans;
    }
    int math(vector<int>& piles, int m){
        int ans = 0;

        for(auto& p: piles){
            
            ans += p / m;

            if(p % m != 0){
                ans++;
            }
        }
        return ans;
    }
};
