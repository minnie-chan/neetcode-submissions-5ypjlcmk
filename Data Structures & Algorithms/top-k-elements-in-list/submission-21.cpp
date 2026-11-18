class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto& n : nums){
            mp[n]++;
        }
        
        for(auto& [key,value] : mp){
            pq.push({value,key});
        }
        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            // Add the most frequent number to ans
            // Remove it from the heap
            k--;
        }
        return ans;
    }
};
