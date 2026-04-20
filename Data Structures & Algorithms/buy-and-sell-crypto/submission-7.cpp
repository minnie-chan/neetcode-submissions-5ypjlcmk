class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int mdz = 0 ;

        while(right < prices.size()){
             if(prices[right] > prices[left]){
                
                mdz = max(mdz, prices[right] - prices[left]);
                
                right ++;
            } 
            
             else if(prices[right] <= prices[left] || prices[left] == prices[right]) { 
               prices[left] = prices[right];
                left ++;
                
            }
            right ++;
            
            
        }
        return mdz;
    }
};
