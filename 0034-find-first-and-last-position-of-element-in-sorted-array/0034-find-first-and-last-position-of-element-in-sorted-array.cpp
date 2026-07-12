class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // Target not found
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return {first, last};
    }
};