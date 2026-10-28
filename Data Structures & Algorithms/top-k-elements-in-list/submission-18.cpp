class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto& n : nums){
            mp[n]++;
        }

        for(auto& [key,value] : mp){
            pq.push({value,key});
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
