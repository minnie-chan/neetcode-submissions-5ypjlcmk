class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;

        while(left < right){
            int middle = left + (right - left) / 2;

           if(nums[middle] > nums[right]){
                left = middle + 1;
                if(nums[middle] == target){
                    return middle;
                }
           } else if (nums[middle] <= nums[right]){
                right = middle -1;//would it make snese to dercemtn it ?
                 if(nums[middle] == target){
                    return middle;
                }
           }
        }
        return -1;
    }
};
