class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> vc(nums.size(), 1);
       
       int left = 1;
       for(int i = 0; i < nums.size(); i++ ){
        vc[i] = left;
        left *= nums[i];
       }
       int right = 1;
       for (int ii = nums.size() -1; ii >= 0 ; ii--){
            vc[ii] *= right;
            right *= nums[ii];
       }
        return vc;
    }
};
