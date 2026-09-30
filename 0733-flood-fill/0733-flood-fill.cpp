class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int c) {
        int m = image.size();
        int n = image[0].size();

        image[row][col] = color;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               image[nrow][ncol] == c) {
                
                dfs(image, nrow, ncol, color, c);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];

        if(c == color)
            return image;

        dfs(image, sr, sc, color, c);

        return image;
    }
};