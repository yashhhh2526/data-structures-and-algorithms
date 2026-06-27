class Solution {
private:
    void solve(int idx, vector<int>& nums,
               vector<vector<int>>& res,
               vector<int>& curr, int n,int target) {


        if(target == 0){
            res.push_back(curr);
        }

        for (int i = idx; i < n; i++) {

            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            if(nums[i]>target){
                break;
            }

            curr.push_back(nums[i]);
            solve(i + 1, nums, res,curr, n,target-nums[i]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums,int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> curr;

        solve(0, nums, res, curr, nums.size(),target);

        return res;
    }
};