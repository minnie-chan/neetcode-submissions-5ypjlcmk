class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int ans = 0;
        int r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int mid = l + (r - l) /2;

            int hours = hoursNeeded(piles,mid);

            if (hours <= h) {
                ans = mid;
                r = mid - 1;
            } else if( hours > h){
                l = mid + 1;
            }
        }
        return ans;
    }
    int hoursNeeded(vector<int>& piles, int speed){
        int hours = 0;


        for(auto& p: piles){
            hours += p / speed;

            if (p % speed != 0) {
                hours++;
            }
        }
        return hours;
    }
};
