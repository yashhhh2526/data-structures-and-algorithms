class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               vis[nrow][ncol] == 0 &&
               grid[nrow][ncol] == '1') {
                
                dfs(grid, vis, nrow, ncol);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0 && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
};