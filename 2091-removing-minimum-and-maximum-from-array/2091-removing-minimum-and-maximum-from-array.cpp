class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini, maxi);
        int right = max(mini, maxi);

       
        int a = right + 1;

       
        int b = n - left;

       
        int c = (left + 1) + (n - right);

        return min({a, b, c});
    }
};