class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int ans = 0;
        if(prices.size() == 1){
            return 0;
        }

        while(r < prices.size()){
            int math = prices[r] - prices[l];
            if(prices[l] > prices[r]){
                l = r;
                r++;
            }else {
                r++;
            }

            ans = max(ans, math);
        }
        return ans;
    }
};
