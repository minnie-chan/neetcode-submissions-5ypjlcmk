class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int middle = l + (r - l) / 2; 
            if (nums[middle] == target) {
                return middle;
            }
            if (nums[l] <= nums[middle]) {
                if (nums[l] <= target && target < nums[middle]) {
                    r = middle - 1;
        // which pointer moves?
                } else {
        // which pointer moves?
                    l = middle + 1;
                }
            } else {
                if(nums[r] >= target && target > nums[middle]){
                    l = middle + 1;
                } else {
                    r = middle - 1;
                }
            }
        }
        return -1;
    }
};
