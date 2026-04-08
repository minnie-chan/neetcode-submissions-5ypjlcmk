class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int r = heights.size();
        int c = heights[0].size();
        
        vector<vector<bool>> pacific(r, vector<bool>(c,false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));
        queue<pair<int,int>> qPacific;
        queue<pair<int,int>> qAtlantic;
        vector<vector<int>> ans; 
        for(int i = 0; i < r; i++){
            qPacific.push({i,0});
            pacific[i][0] = true;
            atlantic[i][c-1] = true;
            qAtlantic.push({i,c-1});
        }
        for(int j = 0; j < c; j++){
            qPacific.push({0,j});
            qAtlantic.push({r-1,j});
            pacific[0][j] = true;
            atlantic[r-1][j] = true;
        }
        
        while(!qPacific.empty()) {
            auto cur = qPacific.front();
            qPacific.pop();

            int x = cur.first;
            int y = cur.second;

            for(int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c &&
                    !pacific[nx][ny] &&
                    heights[nx][ny] >= heights[x][y]) {
                    
                    pacific[nx][ny] = true;
                    qPacific.push({nx, ny});
                }
            }
        }
        while(!qAtlantic.empty()) {
            auto cur = qAtlantic.front();
            qAtlantic.pop();

            int x = cur.first;
            int y = cur.second;

            for(int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c &&
                    !atlantic[nx][ny] &&
                    heights[nx][ny] >= heights[x][y]) {
                    
                    atlantic[nx][ny] = true;
                    qAtlantic.push({nx, ny});
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }    
        return ans;
    }
};
