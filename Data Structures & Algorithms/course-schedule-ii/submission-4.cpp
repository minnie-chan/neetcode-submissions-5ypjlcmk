class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        vector<int> ans;
        for (auto& p : prerequisites) {
            int course = p[0];
            int pre = p[1];

            graph[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int hold = q.front();
            q.pop();
            ans.push_back(hold);

            for (int nei : graph[hold]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }
        return ans ;
    }
};
