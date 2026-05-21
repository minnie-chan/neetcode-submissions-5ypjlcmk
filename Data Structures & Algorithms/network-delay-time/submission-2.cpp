class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> vc(n+1);
        
        for(auto time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            vc[u].push_back({v,w});
        }

        vector<int> v(n+1, INT_MAX);
        v[k] = 0;

        priority_queue<pair<int,int>,
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > v[node]) {
                continue;
            }

            for (auto& [neighbor, weight] : vc[node]) {
                int newDist = currDist + weight;

                if (newDist < v[neighbor]) {
                    v[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (v[i] == INT_MAX) {
                return -1;
            }

            answer = max(answer, v[i]);
        }

        return answer;
    }
};
