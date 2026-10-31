class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto& n : nums){
            mp[n]++;
        }

        for(auto& [key,value] : mp){
            pq.push({value,key});
        }
        while(k != 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
