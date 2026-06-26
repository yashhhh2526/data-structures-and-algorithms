class Solution {
private:
    void solve(vector<int>& nums,
               vector<vector<int>>& res,
               vector<int>& curr,
               int i,
               int k,
               int sum) {

        if (sum == k) {
            res.push_back(curr);
            return;
        }

        if (i == nums.size() || sum > k)
            return;

        // Take (stay at same index)
        curr.push_back(nums[i]);
        solve(nums, res, curr, i, k, sum + nums[i]);

        curr.pop_back();

        // Not take
        solve(nums, res, curr, i + 1, k, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> res;
        vector<int> curr;

        solve(candidates, res, curr, 0, target, 0);

        return res;
    }
};