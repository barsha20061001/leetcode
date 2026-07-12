class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Special overflow case.

        long long a = abs((long long)dividend); // Convert both numbers to positive.
        long long b = abs((long long)divisor);
        // We first cast to long long because abs(INT_MIN) overflows for int.

        long long ans = 0; // Stores the quotient.

        while (a >= b) { // Keep subtracting divisor until dividend becomes smaller.

            long long temp = b; // Current divisor multiple.
            long long multiple = 1;

            while ((temp << 1) <= a) { // Double the divisor until doubling again would exceed the dividend.
                temp <<= 1; 
                // Equivalent to temp = temp * 2; (using only bit operations).
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};