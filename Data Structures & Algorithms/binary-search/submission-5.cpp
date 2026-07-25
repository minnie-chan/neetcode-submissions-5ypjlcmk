class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r){

            int middle = l + (r - l) / 2;

            if(nums[middle] < target){
                l++;
            } else if(nums[middle] > target){
                r--;
            } else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
};
