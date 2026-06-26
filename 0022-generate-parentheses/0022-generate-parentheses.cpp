class Solution {
    void solve(string curr, int open, int close, int n,
               vector<string>& ans) {
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            solve(curr + '(', open + 1, close, n, ans);
        }

        if (close < open) {
            solve(curr + ')', open, close + 1, n, ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", 0, 0, n, ans);
        return ans;
    }
};