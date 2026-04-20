class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1;
        int right = *max_element(weights.begin(), weights.end());
        while(left < right){
            int middle = left + (right - left) / 2;
            int mxc = 0;
            for(auto& siz : weights){
                mxc += ceil(static_cast<double>(siz) + middle);
            }
            if(mxc > days){
                left = middle + 1;
            } 
             else {
                right = middle;
            }
        }
        return left;
    }
};