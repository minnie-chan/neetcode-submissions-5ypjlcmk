class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using T = pair<int, pair<int,int>> ;
        int rows = heights.size();
        int cols = heights[0].size();
        int directons[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        priority_queue<T, vector<T>, greater<T>> pq;
        const int INF = 1e9;
        vector<vector<int>> dist(rows, vector<int>(cols,INF));
        dist[0][0] = 0;
        
        pq.push({0, {0,0}});
        while(!pq.empty()){ 
            auto [effort, coord] = pq.top();
            pq.pop();
            int x  = coord.first;
            int y  = coord.second;
            if(x == rows - 1 && y == cols - 1){
                return effort;
            }
            if(effort > dist[x][y]) {
                continue;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + directons[i][0];
                int ny = y + directons[i][1];

               if(nx < 0 || nx >= rows || ny < 0 || ny >= cols){
                continue;
               }
               int step = abs(heights[nx][ny] - heights[x][y]);
               int newEffort = max(effort, step);

               if(newEffort < dist[nx][ny]){
                dist[nx][ny] = newEffort;
                pq.push({newEffort, {nx, ny}});
               }
            }
        }
        return 0;
    }
};