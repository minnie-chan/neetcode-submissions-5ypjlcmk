class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto e: edges){
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

       if (!dfs(0, -1, visited, adj)) return false;

        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
    bool dfs(int node, int parent,vector<bool>& visited,vector<vector<int>>& adj){
        
        
        visited[node] = true;

        for (int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(!dfs(neighbor,node,visited,adj) ){
                    return false;
                }
            }else if(neighbor != parent){
                return false;
            }

        }
        return true;
    }
};
