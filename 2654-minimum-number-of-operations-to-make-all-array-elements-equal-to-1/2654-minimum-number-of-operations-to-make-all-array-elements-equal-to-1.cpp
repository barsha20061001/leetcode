class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int totalGcd = 0;

        for (int num : nums) {
            if (num == 1)
                ones++;

            totalGcd = gcd(totalGcd, num);
        }

        if (ones > 0)
            return n - ones;

        if (totalGcd != 1)
            return -1;

        int minLength = n;

        for (int i = 0; i < n; i++) {
            int currentGcd = 0;

            for (int j = i; j < n; j++) {
                currentGcd = gcd(currentGcd, nums[j]);

                if (currentGcd == 1) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }

        return (minLength - 1) + (n - 1);
    }
};