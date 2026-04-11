class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;

    // build graph
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
            //shoudlnt we fill with the reso fo the numbers tho liek why dont we fill a with i and b with i +1
            // fill this
        }
        vector<int> state(numCourses, 0);
        

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i,state,graph)) return false;
        }
        return true;
    }
    bool dfs(int node,vector<int>& state, unordered_map<int, vector<int>>& graph  ) {
        if (state[node] == 1) return false; // cycle
        if (state[node] == 2) return true;  // already safe

        state[node] = 1;

        for (int nei : graph[node]) {
            if (!dfs(nei,state,graph)) {
                return false;
            }
        }

        state[node] = 2;
        return true;
    }
};
