class Solution {
private:
    int prefixSum(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int l = 0;
        int odds = 0;
        int cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] % 2 == 1)
                odds++;

            while (odds > goal) {
                if (nums[l] % 2 == 1)
                    odds--;
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return prefixSum(nums, k) - prefixSum(nums, k - 1);
    }
};