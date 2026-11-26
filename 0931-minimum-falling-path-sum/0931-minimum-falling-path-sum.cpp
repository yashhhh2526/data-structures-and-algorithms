class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else {
                    int u = INT_MAX;
                    int l = INT_MAX;
                    int r = INT_MAX;

                    u = matrix[i][j] + dp[i-1][j];

                    if(j-1 >= 0) {
                        l = matrix[i][j] + dp[i-1][j-1];
                    }

                    if(j+1 < n) {
                        r = matrix[i][j] + dp[i-1][j+1];
                    }

                    dp[i][j] = min({u, l, r});
                }
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};