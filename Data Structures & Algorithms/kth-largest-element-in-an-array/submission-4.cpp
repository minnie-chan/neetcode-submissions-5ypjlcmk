class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto& n: nums){
            pq.push(n);
        }
        int a = 1;
        while(a != k){
            pq.pop();
            a++;
        }
        return pq.top();
    }
};
