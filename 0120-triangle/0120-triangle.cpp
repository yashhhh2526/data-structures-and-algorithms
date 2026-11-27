class Solution {
private:
    int solve(int i, int j, int m, vector<vector<int>>& dp,
              vector<vector<int>>& triangle) {

        if(i == m-1){
            return triangle[i][j];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int down = triangle[i][j] + solve(i+1, j, m, dp, triangle);
        int diagonal = triangle[i][j] + solve(i+1, j+1, m, dp, triangle);

        return dp[i][j] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));

        return solve(0, 0, m, dp, triangle);
    }
};