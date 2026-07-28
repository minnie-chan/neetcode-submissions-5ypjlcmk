class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int middle = l + (r - l) / 2;

            if(nums[middle] > nums[r]){
                l = middle + 1;
            } else {
                r = middle;
            }
        }
        return nums[r];
    }
};
