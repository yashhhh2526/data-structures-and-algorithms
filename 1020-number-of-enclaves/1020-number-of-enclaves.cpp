class Solution {
private:
    int m, n;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
               vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(grid, vis, nrow, ncol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // First row and last row
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1 && vis[0][j] == 0)
                dfs(grid, vis, 0, j);

            if(grid[m-1][j] == 1 && vis[m-1][j] == 0)
                dfs(grid, vis, m-1, j);
        }

        // First column and last column
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1 && vis[i][0] == 0)
                dfs(grid, vis, i, 0);

            if(grid[i][n-1] == 1 && vis[i][n-1] == 0)
                dfs(grid, vis, i, n-1);
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};