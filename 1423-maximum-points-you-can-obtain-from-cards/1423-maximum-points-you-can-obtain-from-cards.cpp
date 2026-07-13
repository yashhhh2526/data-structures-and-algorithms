class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == n)
            return total;

        int l = 0;
        int sum = 0;
        int ans = INT_MIN;

        for (int r = 0; r < n; r++) {
            sum += cardPoints[r];

            while (r - l + 1 > n - k) {
                sum -= cardPoints[l];
                l++;
            }

            if (r - l + 1 == n - k) {
                ans = max(ans, total - sum);
            }
        }

        return ans;
    }
};