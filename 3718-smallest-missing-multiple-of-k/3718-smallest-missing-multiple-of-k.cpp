class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vis(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] % k == 0 && nums[i] / k <= n) {
                vis[nums[i] / k] = 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                return i * k;
            }
        }

        return (n + 1) * k;
    }
};