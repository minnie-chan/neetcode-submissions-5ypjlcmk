class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto& a : nums){
            mp[a]++;
        }
        vector<int> ans;
        for(auto& [key,value] : mp){
            pq.push({value,key});
        }

        for(int i = 0; i < k; i++){
            
            ans.push_back(pq.top().second);
            pq.pop();
            
        }

        return ans;
    }
};
