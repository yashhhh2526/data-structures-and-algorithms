class Solution {
private:
    void solve(int idx, vector<int>& nums,
               vector<vector<int>>& res,
               vector<int>& curr, int n) {

        res.push_back(curr);

        for (int i = idx; i < n; i++) {

            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

            curr.push_back(nums[i]);
            solve(i + 1, nums, res, curr, n);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> curr;

        solve(0, nums, res, curr, nums.size());

        return res;
    }
};