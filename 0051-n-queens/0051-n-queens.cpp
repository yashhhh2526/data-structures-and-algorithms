class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        int r = row, c = col;

        while (r >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
        }

        r = row;
        c = col;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }

    void solve(int row,
               vector<string>& board,
               vector<vector<string>>& ans,
               int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                solve(row + 1, board, ans, n);

                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};