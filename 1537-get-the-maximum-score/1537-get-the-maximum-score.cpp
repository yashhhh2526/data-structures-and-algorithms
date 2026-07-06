class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxSum(vector<int> &a, vector<int> &b) {
        int n1 = a.size();
        int n2 = b.size();

        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0, sum = 0;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                sum1 += a[i];
                i++;
            } 
            else if (a[i] > b[j]) {
                sum2 += b[j];
                j++;
            } 
            else {
                sum += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < n1) {
            sum1 += a[i];
            i++;
        }

        while (j < n2) {
            sum2 += b[j];
            j++;
        }

        sum += max(sum1, sum2);

        return sum % MOD;
    }
};