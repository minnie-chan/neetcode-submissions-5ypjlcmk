class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long left = *max_element(weights.begin(), weights.end());
        long long right;
        long long total =0;
        for(auto& siz:weights){
            total += siz;
        }
        right = total;
        while(left < right){
            long long middle = left + (right - left) / 2;
            long long load = 0;
            long long need_days = 1;
            for(auto& aa : weights){
                if(load + aa <= middle){
                        load += aa;
                } else{
                    need_days++;
                    load = aa;
                }
            }
            if(need_days > days){
                left = middle + 1;
            } else {
                right = middle ;
                }
        }
        return left;
    }
};