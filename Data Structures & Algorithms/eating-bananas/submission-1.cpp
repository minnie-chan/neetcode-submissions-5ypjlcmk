class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){
            int middle = left + (right - left) / 2;
            int  hours = 0;
            for(auto& zz : piles){
               hours += ceil(static_cast<double>(zz) / middle);
            }

            if(hours > h){

                left = middle + 1;
            } else { 
                right  = middle ;
            }
        }
        return left;
    }
};
