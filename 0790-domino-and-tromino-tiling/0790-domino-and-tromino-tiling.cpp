class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;

        long long prev3 = 1; // dp[0]
        long long prev2 = 1; // dp[1]
        long long prev1 = 2; // dp[2]

        for (int i = 3; i <= n; i++) {
            long long current = (2 * prev1 + prev3) % MOD;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};