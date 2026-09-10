class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int ans = *max_element(piles.begin(),piles.end());
        int right = *max_element(piles.begin(),piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2;

            int a = math(piles,mid);
            if(a > h){
                left = mid + 1;
            } else if(a <= h){
                ans = min(ans,mid);
                right = mid - 1;
            }
        }
        return ans;
    }
    int math(vector<int>& piles, int& h){
        int a = h;
        long long track = 0;
        for(auto& p : piles){
            
            track += p / a;
            if(p % a != 0){
                track++;
            }
        }
        return track;
    }
};
