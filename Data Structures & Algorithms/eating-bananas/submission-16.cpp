class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(l <= r ){
            int mid = l + (r - l) / 2;

            long long check = math(piles,mid);

            if(check > h){
                l = mid + 1;
            } else{
                ans = min(ans, mid);
                r = mid -1;
            }
        }
        return ans;
    }
    long long math(vector<int>& piles, int h){
        long long sum = 0;
        for(auto& p : piles){

            sum += p / h;

            if(p % h != 0){
                sum++;
            }
        }
        return sum;
    }
};
