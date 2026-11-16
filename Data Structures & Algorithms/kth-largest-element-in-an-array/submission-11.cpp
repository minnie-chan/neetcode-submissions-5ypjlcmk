class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int track = 0;
        for(auto& n : nums){
            if(pq.size() != k){
                pq.push(n);
                track = pq.top();
            }else if(n > track  && pq.size() == k){
                pq.pop();
                pq.push(n);
                track = pq.top();
            }
            
        }
        return pq.top();
    }
};
