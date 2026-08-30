class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 1;
        }

        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();

        // from front
        int a = max(mini, maxi) + 1;

        // from back
        int b = n - min(mini, maxi);

        // from front and back
        int c = min(mini, maxi) + 1 + n - max(mini, maxi);

        return min({a, b, c});
    }
};

