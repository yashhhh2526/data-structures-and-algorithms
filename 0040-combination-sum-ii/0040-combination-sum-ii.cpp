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

        if (sum > k || i >= nums.size())
            return;

        // Take
        curr.push_back(nums[i]);
        solve(nums, res, curr, i + 1, k, sum + nums[i]);
        curr.pop_back();

        // Skip duplicates
        int j = i;
        while (j + 1 < nums.size() && nums[j] == nums[j + 1])
            j++;

        // Not take
        solve(nums, res, curr, j + 1, k, sum);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        solve(candidates, res, curr, 0, target, 0);

        return res;
    }
};