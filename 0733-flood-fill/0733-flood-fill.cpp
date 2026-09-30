class Solution {
private:
    vector<vector<int>> vis;

    void dfs(vector<vector<int>>& image, int row, int col, int color, int c) {
        int m = image.size();
        int n = image[0].size();

        vis[row][col] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               vis[nrow][ncol] == 0 &&
               image[nrow][ncol] == c) {

                image[nrow][ncol] = color;
                dfs(image, nrow, ncol, color, c);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vis = vector<vector<int>>(m, vector<int>(n, 0));

        int c = image[sr][sc];

        if(c == color)
            return image;

        image[sr][sc] = color;

        dfs(image, sr, sc, color, c);

        return image;
    }
};