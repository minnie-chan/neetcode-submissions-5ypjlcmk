class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int peak = 0;

        for(int i = 0; i< nums.size()-1; i++){
            peak = max(peak, i+ nums[i]);

            if(i == currentEnd){
                jumps++;
                currentEnd = peak;
            }
        }
        return jumps;
    }

};
