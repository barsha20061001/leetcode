class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> primes = {2, 3, 5, 7};

        for (int i = 0; i < n; i++) {
            vector<int> sum(4, 0);
            vector<int> minimum(4, INT_MAX);
            vector<int> maximum(4, 0);

            for (int j = i; j < n; j++) {
                int number = nums[j];

                for (int p = 0; p < 4; p++) {
                    int exponent = 0;
                    int value = number;

                    while (value % primes[p] == 0) {
                        exponent++;
                        value /= primes[p];
                    }

                    sum[p] += exponent;
                    minimum[p] = min(minimum[p], exponent);
                    maximum[p] = max(maximum[p], exponent);
                }

                bool valid = true;

                for (int p = 0; p < 4; p++) {
                    // prod = gcd * lcm for every prime factor
                    if (sum[p] != minimum[p] + maximum[p]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};