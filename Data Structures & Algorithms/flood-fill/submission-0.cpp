class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();

        int original = image[sr][sc];

        if (original == color) {
            return image;
        }

        dfs(sr, sc, image, original, color);
        return image;
    }
    void dfs(int r, int c, vector<vector<int>>& image, int original, int color) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) {
            return;
        }
        if (image[r][c] != original) {
            return;
        }
        image[r][c] = color;

        dfs(r + 1, c, image, original, color);
        dfs(r - 1, c, image, original, color);
        dfs(r, c + 1, image, original, color);
        dfs(r, c - 1, image, original, color);
    }
};