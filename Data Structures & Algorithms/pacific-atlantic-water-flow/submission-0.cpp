class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // Pacific: top row
    for (int c = 0; c < cols; c++) {
        if (!pacific[0][c]) {
        dfs(0, c, heights, pacific, rows, cols, dirs);
        }
    }

    // Pacific: left column
    for (int r = 0; r < rows; r++) {
        if (!pacific[r][0]) {
        dfs(r, 0, heights, pacific, rows, cols, dirs);
        }
    }
        // Atlantic: bottom row
    for (int c = 0; c < cols; c++) {
        if (!atlantic[rows - 1][c]) {
        dfs(rows - 1, c, heights, atlantic, rows, cols, dirs);
        }
    }

        // Atlantic: right column
    for (int r = 0; r < rows; r++) {
        if (!atlantic[r][cols - 1]) {
        dfs(r, cols - 1, heights, atlantic, rows, cols, dirs);
        }
    }
        vector<vector<int>> result;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
        if (pacific[r][c] && atlantic[r][c]) {
            result.push_back({r, c});
        }
      }
    }

    return result;

    }
    void dfs(int r, int c,
         vector<vector<int>>& heights,
         vector<vector<bool>>& visited,
         int rows, int cols,
         int dirs[4][2]) {
    
    visited[r][c] = true;

    for (int k = 0; k < 4; k++) {
        int nr = r + dirs[k][0];
        int nc = c + dirs[k][1];

        // 1) bounds check
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

        // 2) already visited for this ocean? skip
        if (visited[nr][nc]) continue;

        // 3) reverse-flow condition: can only go to same or HIGHER height
        if (heights[nr][nc] < heights[r][c]) continue;

        dfs(nr, nc, heights, visited, rows, cols, dirs);
    }
  }

};
