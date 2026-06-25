class Solution {
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long half = power(x, n / 2);
        

        if (n %2 == 0) {
            return (half*half)%MOD;
        }

        return (x*half*half)%MOD ;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long ans =
            (power(5, evenPos) * power(4, oddPos)) % MOD;

        return (int)ans;
    }
};