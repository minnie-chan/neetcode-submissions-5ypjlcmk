class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        pq.push({grid[0][0], 0, 0});
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == grid.size() - 1 && c == grid[0].size() - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int newR = r + dirs[i].first;
                int newC = c + dirs[i].second;

                // bounds check
                if(newR >= grid.size() || newC >= grid[0].size() || newR < 0 || newC < 0){
                    continue;
                }
                if (!visited[newR][newC]) {
                    int newTime = max(time, grid[newR][newC]);
                    pq.push({newTime, newR, newC});
                }
            }
        }
    }
};
