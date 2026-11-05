class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for(auto& p : points){
            int a = p[0];
            int b = p[1];

            int math = a * a + b * b;
            pq.push({math, p});
        }

        while(pq.size() > k){
            pq.pop();
            
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
