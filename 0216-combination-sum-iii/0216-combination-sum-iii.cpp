class Solution {
private:
    void solve(int idx,
               vector<vector<int>>& res,
               vector<int>& curr,
               int sum,
               int k,
               int target) {

        if (sum > target)
            return;

        if (curr.size() == k) {
            if (sum == target) {
                res.push_back(curr);
            }
            return;
        }

        for (int i = idx; i <= 9; i++) {
            curr.push_back(i);
            solve(i + 1, res, curr, sum + i, k, target);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(1, res, curr, 0, k, n);

        return res;
    }
};