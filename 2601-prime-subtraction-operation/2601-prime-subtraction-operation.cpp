class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime(maxValue + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= maxValue; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxValue; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int previous = 0;

        for (int value : nums) {
            int limit = value - previous;
            int prime = 0;

            for (int p = limit - 1; p >= 2; p--) {
                if (isPrime[p]) {
                    prime = p;
                    break;
                }
            }

            int current = value - prime;

            if (current <= previous) {
                return false;
            }

            previous = current;
        }

        return true;
    }
};