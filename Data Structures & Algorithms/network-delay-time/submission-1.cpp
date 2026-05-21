class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // graph[u] stores {v, w}
        // meaning u -> v costs w
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            graph[u].push_back({v, w});
        }

        // dist[i] = shortest known time from k to node i
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // min-heap: {distanceSoFar, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // If this is an old worse distance, skip it
            if (currDist > dist[node]) {
                continue;
            }

            // Try going from this node to each neighbor
            for (auto& [neighbor, weight] : graph[node]) {
                int newDist = currDist + weight;

                // Found a cheaper way to reach neighbor
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            // If any node was never reached
            if (dist[i] == INT_MAX) {
                return -1;
            }

            // We need the time when the LAST node receives signal
            answer = max(answer, dist[i]);
        }

        return answer;
    }
};