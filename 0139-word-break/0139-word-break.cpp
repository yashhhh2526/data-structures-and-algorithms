class Solution {
private:
    vector<int> dp;

    bool issafe(string &s, int start, int end, vector<string> &dict) {
        string curr = s.substr(start, end - start + 1);

        for (auto &word : dict) {
            if (word == curr)
                return true;
        }
        return false;
    }

    bool solve(int idx, string &s, vector<string> &wordDict) {
        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int i = idx; i < s.size(); i++) {
            if (issafe(s, idx, i, wordDict)) {
                if (solve(i + 1, s, wordDict))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        dp.assign(s.size(), -1);
        return solve(0, s, wordDict);
    }
};