class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(intervals.begin(), intervals.end());

        vector<int> ans(queries.size(), -1);
        vector<pair<int,int>> q;
        
        for(int i = 0; i < queries.size();i++){
            q.push_back({queries[i],i });
        }
        sort(q.begin(), q.end());
        int i = 0; // pointer for intervals
        for (auto& [qVal, idx] : q) {
            while (i < intervals.size() && intervals[i][0] <= qVal) {
                int left = intervals[i][0];
                int right = intervals[i][1];

                pq.push({right - left + 1, right});
                i++;
            }
            while (!pq.empty() && pq.top().second < qVal) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }
        return ans;
    }
};
