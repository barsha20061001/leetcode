class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int minimizeSet(int divisor1, int divisor2,
                    int uniqueCnt1, int uniqueCnt2) {
        
        long long lcm = 1LL * divisor1 / gcd(divisor1, divisor2) * divisor2;

        long long left = 1;
        long long right = 2LL * (uniqueCnt1 + uniqueCnt2);

        while (left < right) {
            long long mid = left + (right - left) / 2;

            // Numbers usable by arr1
            long long available1 = mid - mid / divisor1;

            // Numbers usable by arr2
            long long available2 = mid - mid / divisor2;

            // Numbers usable by at least one array
            long long availableTotal = mid - mid / lcm;

            bool possible =
                available1 >= uniqueCnt1 &&
                available2 >= uniqueCnt2 &&
                availableTotal >= 1LL * uniqueCnt1 + uniqueCnt2;

            if (possible)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};