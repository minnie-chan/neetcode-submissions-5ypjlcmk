class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
                count++;
            }
        }

        return count;
    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }
};