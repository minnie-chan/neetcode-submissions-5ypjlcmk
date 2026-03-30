class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long left = *max_element(weights.begin(), weights.end());
        long long total = 0;
        for(auto& zz : weights){
             total += zz;
               
        }
           long long right = total;
             

        while(left < right){
            long long  mid = left + (right - left) / 2;
                long long load = 0;
                    long long days_used = 1;
             for(auto& siz: weights){
             if(load + siz > mid ){
                days_used ++;
                load = 0;
                
             } 
             load += siz; 
             }
                if(days_used > days){
                left = mid + 1;
                    } else {
                         right = mid;
                    }
        }
        return (int)left;
    }
};