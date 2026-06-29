class Solution {
private:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> &curr,
               vector<vector<string>> &res) {
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, curr, res);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(0, s, curr, res);
        return res;
    }
};