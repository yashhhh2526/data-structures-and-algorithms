class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1){
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    continue;
                }
                else{
                    int u = 0;
                    int d = 0;
                    if(i>0) u = dp[i-1][j];
                    if(j>0) d = dp[i][j-1];
                    dp[i][j] = u + d;
                }
            }
        }
        return dp[m-1][n-1];
    }
};