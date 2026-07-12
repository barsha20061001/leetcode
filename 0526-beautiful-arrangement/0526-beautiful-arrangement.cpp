class Solution {
public:
    int countArrangement(int n) {
        vector<int> memo(1 << n, -1);
        // Creates a DP (memoization) array.
        // Each index represents one bitmask state.

        function<int(int)> solve = [&](int mask) {
            // Creates a recursive function.Parameter: mask tells which numbers have already been used.
            int position = __builtin_popcount(mask) + 1; // counts how many bits are set

            if (position > n)
                return 1;

            if (memo[mask] != -1)
                return memo[mask];

            int count = 0;

            for (int num = 1; num <= n; num++) {
                int bit = 1 << (num - 1);

                if ((mask & bit) == 0 &&
                    (num % position == 0 || position % num == 0)) {
                    count += solve(mask | bit);
                }
            }

            return memo[mask] = count;
        };

        return solve(0);
    }
};