class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> result;
    
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
        }
        vector<int> state(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            dfs(i,state,graph,result);
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    bool dfs(int node,vector<int>& state, unordered_map<int, vector<int>>& graph,vector<int>& result) {
        if (state[node] == 1) return false; 
        if (state[node] == 2){
            result.push_back(node);
            return true;
        };  

        state[node] = 1;

        for (int nei : graph[node]) {
            if (dfs(nei,state,graph,result) == false) {
                return false;
            }
        }

        state[node] = 2;
        result.push_back(node);
        return true;
    }
    
};
