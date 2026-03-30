class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans;
        for(auto& zz : nums){
            pq.push(zz);
            if(pq.size() > k){
                pq.pop();
            }
            }
            ans = pq.top();
        return ans;
     
    }
};
