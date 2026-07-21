class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        long long left = 1, right = 2e9;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            long long count =
                mid / a + mid / b + mid / c
                - mid / ab - mid / ac - mid / bc
                + mid / abc;

            if (count >= n)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};