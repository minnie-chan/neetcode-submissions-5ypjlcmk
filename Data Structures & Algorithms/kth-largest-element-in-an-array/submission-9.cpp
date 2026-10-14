class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        if(nums.size() == 1){
            return nums[0];
        }
        for(auto& n : nums){
            pq.push(n);
        }
        int ans = 0;
        for(int i = 0; i < k - 1;i++){
            pq.pop();

        }
        return pq.top();
    }
};
