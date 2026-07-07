class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        long long place = 1;
        while (n) {
            int rem = n % 10;
            if (rem != 0) {
                sum = sum+rem;
                num =  place* rem + num;
                place = place*10;
            }
            n = n/10;
        }
        return num*sum;
    }
};