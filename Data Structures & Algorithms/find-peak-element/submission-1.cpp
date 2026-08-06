class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        

        while(l < r){
            int midd = l + (r - l) / 2;

            if(nums[midd] < nums[midd + 1]){
                l = midd + 1;
                
            } else {
                r = midd ;
                
            }
        }
        return l;
    }
};