class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int left = 0;
     int right = 1;
     int maxpr = 0;
     int profit = 0;

      while (left < prices.size()) {
        if(prices[right] > prices[left]){
            profit = right - left;
        }
        
        right ++;
        if(prices[left]  >= prices[right]){
            left ++;
        }
        if(maxpr < profit){
            maxpr = profit;
        } 
      }
      return maxpr;
    }
};
