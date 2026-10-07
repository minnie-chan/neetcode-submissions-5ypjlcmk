class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int a = func(piles, mid);
            if (a > h) {
                left = mid + 1;
            } else {
                ans = min(ans, mid);
                right = mid - 1;
            }
            // compute total hours using speed mid
            // then move left or right
        }
        return ans;
    }
    int func(vector<int>& piles, int track) {
        int hours = 0;

        for (auto& p : piles) {
            // add ceil(p / speed) to hours
            hours += p / track;

            if(p % track){
                hours++;
            }
        }

        return hours;
    }
};
