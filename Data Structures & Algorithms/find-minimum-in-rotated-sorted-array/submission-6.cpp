class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1;

        while(l < r){
            int middle = l + (r - l) / 2;

            if(nums[middle] < nums[r]){
                r = middle;
            } else {
                l = middle + 1;
            }
        }
        return nums[l];
    }
};
