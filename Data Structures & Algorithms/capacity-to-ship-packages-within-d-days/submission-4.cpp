class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        int ans = 0;
        for(int i = 0; i < weights.size(); i++){
            r += weights[i];
        }
        while(l <= r){
            int middle = l + (r - l) /2;
            int a = daysNeeded(weights,middle);

            if(a <= days){
                ans = middle;
                r = middle - 1;
            } else if(a > days){
                l = middle + 1;
            }
        }
        return ans;
    }

    int daysNeeded(vector<int>& weights, int a){
        int days = 1;
        int c = 0;
        for(auto& w : weights){
            if(c + w <= a){
                c += w;
            } else {
                days++;
                c = w;
            }
        }
        return days;
    }
};