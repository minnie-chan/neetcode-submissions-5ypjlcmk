class Solution {
public:
    vector<int> parent;
    vector<int> rankv;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return false; // cycle found

        if (rankv[rootA] < rankv[rootB]) {
            parent[rootA] = rootB;
        } else if (rankv[rootA] > rankv[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rankv[rootA]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};