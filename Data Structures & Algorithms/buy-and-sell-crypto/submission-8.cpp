class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int mdz = 0 ;

        while(right < prices.size()){
             if(prices[right] > prices[left]){
                
                mdz = max(mdz, prices[right] - prices[left]);
                
                
            } 
            
             else  { 
               prices[left] = prices[right];
                
                
            }
            right ++;
            
            
        }
        return mdz;
    }
};
