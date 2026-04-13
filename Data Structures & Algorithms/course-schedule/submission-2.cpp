class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int,vector<int>> mp;
        for(auto b : pre){
            mp[b[1]].push_back(b[0]);
            indegree[b[0]]++;
        }
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto nei: mp[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
            
        }
        if(count == numCourses){
            return true;
        } else {
            return false;
        }
    }
};
