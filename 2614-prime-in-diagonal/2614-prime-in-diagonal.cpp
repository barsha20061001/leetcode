class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;

        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int first = nums[i][i];
            int second = nums[i][n - i - 1];

            if (isPrime(first)) {
                ans = max(ans, first);
            }

            if (isPrime(second)) {
                ans = max(ans, second);
            }
        }

        return ans;
    }
};