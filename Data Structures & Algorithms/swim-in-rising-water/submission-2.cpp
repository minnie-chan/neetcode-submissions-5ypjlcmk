class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
        pq.push({grid[0][0], 0, 0});
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(flag[r][c]){
                continue;
            }
            flag[r][c] = true;

            if(r == grid.size() -1 && c == grid[0].size()-1){
                return time;
            }
            for(int i = 0; i < 4; i++){
                int nX = r + dirs[i].first;
                int nY = c + dirs[i].second;

                if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size()){
                    continue;
                }

                if(!flag[nX][nY]){
                    int newTime = max(time, grid[nX][nY]);
                    pq.push({newTime, nX, nY});
                }
            }
        }
    }
};
